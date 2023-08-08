#pragma once

typedef struct ReadFileParams_s
{
	void removeParentPath(const char* path)
	{
		std::string pathStr(path);
		std::size_t foundPos = pathStr.find("../");
		while (foundPos != std::string::npos) { pathStr.erase(foundPos, 3); foundPos = pathStr.find("../"); }

		char* pCharPath = new char[pathStr.length() + 1]; strcpy_s(pCharPath, pathStr.length() + 1, pathStr.c_str());
		pPath.assign(pCharPath, strlen(pCharPath));
		delete[] pCharPath;
	}

	bool isValidPath(const char* prefix, const char sufix)
	{
		std::string strPath(pPath.c_str());
		size_t prefixLength = strlen(prefix);
		size_t stringLength = strPath.length();
		size_t slashPos = strPath.find(sufix, prefixLength);

		if (stringLength < prefixLength || strPath.find(prefix) != 0 || slashPos == std::string::npos)
			return false;

		return slashPos == stringLength - 1;
	}

	void addPrefix(const char* prefix)
	{
		size_t prefixLength = strlen(prefix);
		size_t originalStringLength = strlen(pPath.c_str());
		size_t totalLength = prefixLength + originalStringLength + 1;

		char* newPath = new char[totalLength];
		strcpy_s(newPath, totalLength, prefix);
		strcat_s(newPath, totalLength, pPath.c_str());
		pPath.assign(newPath, strlen(newPath));
		delete[] newPath;
	}

	char* GetLine(byte* mewpMemFile, int newfileSize, int& newfilePos, char* pBuffer, int bufferSize)
	{
		if (!mewpMemFile || !pBuffer)
			return NULL;

		if (newfilePos >= newfileSize)
			return NULL;

		int i = newfilePos;
		int last = newfileSize;

		if (last - newfilePos > (bufferSize - 1))
			last = newfilePos + (bufferSize - 1);

		int stop = 0;

		while (i < last && !stop)
		{
			if (mewpMemFile[i] == '\n')
				stop = 1;
			i++;
		}

		if (i != filePos)
		{
			int size = i - newfilePos;
			memcpy(pBuffer, mewpMemFile + newfilePos, sizeof(byte) * size);

			if (size < bufferSize)
				pBuffer[size] = 0;

			newfilePos = i;
			return pBuffer;
		}

		return NULL;
	}

	void SetFile(CString* path)
	{
		removeParentPath(path->c_str());

		if (isValidPath("svencoop_", '/'))
		{
			addPrefix("../");
		}

		pMemFile = g_engfuncs.pfnLoadFileForMe((char*)pPath.c_str(), &fileSize);
		filePos = 0;
	}

	bool IsValid()
	{
		return pMemFile;
	}

	bool ReadFile()
	{
		char buffer[512]; memset(buffer, 0, 512);
		int newfilePos = filePos, newfileSize = fileSize;
		byte* newpMemFile = pMemFile;

		if (!newpMemFile)
			return false;

		if (GetLine(newpMemFile, newfileSize, newfilePos, buffer, 511) != NULL)
		{
			filePos = newfilePos;
			pMessage.assign(buffer, strlen(buffer));

			return true;
		}
		return false;
	}

	void FreeFile()
	{
		g_engfuncs.pfnFreeFile(pMemFile);
		pMemFile = nullptr;
		pPath = { 0 };
		pMessage = { 0 };
		fileSize = 0;
		filePos = 0;
	}

	byte* pMemFile;
	CString pPath;
	CString pMessage;
	int fileSize;
	int filePos;
}
ReadFileParams_t;

