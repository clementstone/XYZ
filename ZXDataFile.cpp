#include "stdafx.h"
#include "ZXDataFile.h"

string formats[] = {  // ��ע�⡿����˳��Ҫ��ö�ٶ���һ�£����򷵻س����������ʱλ��Ҫһ��
	"TXT", // x,y,z  �Լ�Լ���ģ������ָ����������������
	"OFF",
	"PCD", 
	"PLY",
	"PTS", // x y z
	"XYZ", // x y z
	"OBJ", // v x y z
	"STL" // vertex x y z
};

ZXDataFile::ZXDataFile(void)
{
}


ZXDataFile::~ZXDataFile(void)
{
}

// ���ӿڡ�����ת��
bool ZXDataFile::Convert(char *inputFileName, DataFormat outFormat)
{

	// STEP 0 ��������ļ�������ʽ
	DataFormat inFormat = GetFormatByFileName(inputFileName);
	string inSeperator = inFormat == F_TXT ? "," : " ";

	stringstream ss;
	ss << inputFileName << "." << formats[outFormat];

	// STEP 1 ͬʱ����������ļ�
	ifstream ifile; // �����ļ�
	ifile.open(inputFileName, ios::in);
	if (!ifile.is_open())
	{
		cout << "Error: �������ļ� " << inputFileName << "����" << endl; 
		return false;
	}
	// �����ȿ���TXT -> XYZ��δ�������
	int iX, iY, iZ;
	switch (inFormat)
	{
	case F_TXT:
	case F_OFF:
	case F_PCD:
	case F_PLY:
	case F_PTS:
	case F_XYZ:
		iX = 0;
		iY = 1;
		iZ = 2;
		break;
	case F_OBJ:
	case F_STL:
		iX = 1;
		iY = 2;
		iZ = 3;
		break;
	default:
		iX = 0;
		iY = 1;
		iZ = 2;
		break;
	}

	ofstream ofile;
	ofile.open(ss.str().c_str(), ios::out);
	if (!ofile.is_open())
	{
		cout << "Error��������ļ� " << ss << " ����" << endl;
		return false;
	}
	string outSeperator = outFormat == F_TXT ? "," : " ";

	// STEP 2 ��ʼ��һ��дһ�е�ѭ��
	int lineNum = 0;  // �ļ�������
	char buffer[256];
	while (!ifile.eof())
	{
		if (lineNum % 10000 == 0)
		{
			cout << lineNum << endl;  // ÿ1������һ�½���
		}
		// STEP 2.1 �ȶ� -------------------------------

		// �ļ�ͷ�Ľ����봦��δ�������

		// �ȶ�����,���ָ����и�
		ifile.getline(buffer, 256);
		string line = string(buffer);
		vector<string> numStr = ZXTool::split(line, inSeperator);

		if (numStr.size() > iZ)
		{
			float x = atof(numStr[iX].c_str());
			float y = atof(numStr[iY].c_str());
			float z = atof(numStr[iZ].c_str());

			// STEP 2.2 ��д -------------------------------

			// �ļ�ͷ�������봦��δ�������

			// д������
			if (outFormat == F_STL)
			{
				ofile << "vertex ";
			}
			stringstream xyz;
			xyz  << x << outSeperator << y << outSeperator << z << endl;

			ofile << xyz ;

			lineNum++;
		}
	}

	// д����������...... �����ô�� �ߺ��滹�����ɣ�����

	// STEP 3 �ر��ļ�
	ifile.close();
	ofile.close();

	return true; // ת���ɹ�
}


// �����ļ���չ�����ж��ļ�����
DataFormat ZXDataFile::GetFormatByFileName(char *fileName)
{

	string name = string(fileName);
	vector<string> str = split(name, ".");
	string extension = str[str.size() - 1];

	transform(extension.begin(), extension.end(), extension.begin(), toupper);

	for (int i = 0; i < 10; i++)
	{
		if (formats[i] == extension)
		{
			return (DataFormat) i;
		}
	}

	return F_TXT;
}

vector<string> split(const string &s, const string &seperator) {
	size_t last = 0;
	size_t index = s.find_first_of(seperator);
	vector<string> result;

	while (index != string::npos)
	{
		result.push_back(s.substr(last, index-last));
		last = index + 1;
		index = s.find_first_of(seperator, last);
	}

	if (index-last>0)
	{
		result.push_back(s.substr(last, index-last));
	}
	return result;

}