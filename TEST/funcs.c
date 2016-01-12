#include "Cifte.h"

FILE *openFile(char* mode) {

	byte running = 1;
	char fileName[128];
	FILE *file;
	while (running)
	{
		printf("\n Vuvedete ime na file: ");

		if (!fgets(fileName, 128, stdin))
		{
			return 0;
		}

		fileName[strlen(fileName) - 1] = '\0';

		if (isdigit(fileName[0]) || (getSubstCount(fileName, ".c") != 1))
		{
			printf("\nGreshen file ");
		}
		else
		{
			file = fopen(fileName, mode);
			if (file == NULL)
			{
				perror("Open File");
				system("pause");
				exit(0);
			}
			running = 0;
		}
	}

	return file;
}


void closeFile(FILE *fp) {

	if (fclose(fp) != 0)
	{
		perror("Error closing file");
		system("pause");
		return;
	}
}

void checkFile(FILE * fp)
{
	if (ferror(fp))
	{
		printf("Error in reading from file\n");
	}
	clearerr(fp);
}

unsigned int getSubstCount(const char *haystack, const char *needle)
{
	int count = 0;
	const char *tmp = haystack;
	while (tmp = strstr(tmp, needle)) {
		tmp++;
		++count;
	}
	return count;
}

float executeOpt(FILE *file)
{
	switch (printMenu())
	{
	case '1':
		return (float)option1(file);
	case '2':
		return option2(file);
	case '3':
		return (float)option3(file);
	default:
		break;
	}

	return 0.0f;
}

char printMenu()
{
	printf("\n1 Broi na redovete zapochvashti s { / c }\n"
		"2.Sreden broi na glavni i malki bukvi na red ot programata sprqmo obshtiqt broi glavni i malki bukvi vuv file-a \n"
		"3. Broqt na komentarite po-dulgi ot 1 red \n"
		"4. Izhod\n\n"
		"Molq wudete opciq ot 1 do 4\n");
	byte running = 1;
	
	while(running)
	{
		char option = fgetc(stdin);

		switch (option)
		{
		case '1':
			return '1';
		case '2' :
			return '2';
		case '3':
			return '3';
		case '4':
			exit(0);
		default:
			printf("Molq izberete opciq 1 - 3\n");
			break;
		}
	}

	

	return 0;
}

int option1(FILE *file)
{
	char buffer[BUFSIZ];

	int slashCNum = 0;

	bool lineIsComment = false;

	while (fgets(buffer, BUFSIZ, file))
	{
		for (unsigned int counter = 0; counter < strlen(buffer); ++counter)
		{
			if (buffer[counter] == '/')
			{
				if (buffer[counter + 1] == '/')
				{
					break;
				}
				else if (buffer[counter + 1] == '*')
				{
					break;
				}
				else if (buffer[counter + 1] == ' ' && buffer[counter + 2] == 'c' && buffer[counter + 3] == ' ')
				{
					slashCNum++;
				}
			}
			else if (buffer[counter] == '\t')
			{
				continue;
			}
			else if (buffer[counter] == ' ')
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}

	printf("Broqt na redovete, koito pochvat s { / c } e ");
	return slashCNum;
}

float option2(FILE *file)
{

	char buffer[BUFSIZ];

	float avgLetpLine = 0;
	int newLineNum = 0;

	while (fgets(buffer, BUFSIZ, file))
	{
		checkFile(file);

		for (unsigned int counter = 0; counter < strlen(buffer); ++counter)
		{
			if (buffer[counter] == '\n')
			{
				newLineNum++;
			}
			else if (buffer[counter] >= 'a' && buffer[counter] <= 'z' || buffer[counter] >= 'A' && buffer[counter] <= 'Z')
			{
				avgLetpLine++;
			}
		}
	}
	
	avgLetpLine /= (newLineNum + 1);

	printf("Sreden broi na glavni i malki bukvi na red ot programata sprqmo obshtiqt broi glavni i malki bukvi vuv file-a e ");
	return avgLetpLine;
}

int option3(FILE *file)
{
	char buffer[BUFSIZ];

	int multComNum = 0;


	bool lineIsComment = false,
		isString = false,
		isChar = false;;
	char D =  '"';
	byte hasNewLine = 0;
	while (fgets(buffer, BUFSIZ, file))
	{
		checkFile(file);
		char cleanBuf[BUFSIZ];
		unsigned int counter = 0,
			cleanCounter = 0;

		for (counter; counter < strlen(buffer); ++counter)
		{
			if (buffer[counter] == '/')
			{
				if (buffer[counter + 1] == '/')
				{
					cleanBuf[cleanCounter] = '\0';
					break;
				}
			}
			else if (buffer[counter] == '"' )
			{
				if (!isString && !isChar)
					isString = true;
				else if (buffer[counter - 1] == '\\' && isChar)
				{
					isString = true;
				}
				else
					isString = false;
			}
			else if (buffer[counter] == '\'' && isString)
			{
				if (!isChar)
					isString = false;
				else if (buffer[counter - 1] == '\\')
				{
					isChar = true;
				}
				else
					isChar = false;
			}

			if (!isString && !isChar)
			{
				cleanBuf[cleanCounter] = buffer[counter];
				if (buffer[counter] == '\n')
				{
					cleanBuf[cleanCounter] = '~';
				}
				cleanCounter++;
			}

		}					   

		for (unsigned int i = 0; i < strlen(cleanBuf); i++)
		{
			if (cleanBuf[i] == '/')
			{
				if (cleanBuf[i + 1] == '*')
				{
					lineIsComment = true;
				}
				else if (cleanBuf[i - 1] == '*')
				{
					lineIsComment = false;
					hasNewLine = 0;
				}
			}
			if (cleanBuf[i] == '~' && lineIsComment)
			{
				printf("%s\n", cleanBuf);
				if(!hasNewLine)
				{
					hasNewLine = 1;
					multComNum++;
				}
				break;
			}
		}

		memset(cleanBuf, 0, strlen(buffer));

	}
	printf(" Broqt na komentarite po-dulgi ot 1 red e ");
	return multComNum;
}
