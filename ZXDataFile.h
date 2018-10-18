// ================================================================
//  ZXDataFile.h
//  ���ܶ�λ�����������ļ���ʽת��
//  ���ݵ����ļ���ʽ�����������ݽṹ���жϸ�ʽ���ͣ�����ת��ΪĿ���ʽ
// ----------------------------------------------------------------
//  Created by ������ on 2018.8.2
// ================================================================

#pragma once

enum DataFormat
{
	// ���¾�Ϊ�ı���ʽ
	F_TXT, // x,y,z  �Լ�Լ���ģ������ָ����������������
	F_OFF, // x y z
	F_PCD, // x y z
	F_PLY, // x y z
	F_PTS, // x y z
	F_XYZ, // x y z
	F_OBJ, // v x y z
	F_STL // vertex x y z
};

class ZXDataFile
{
public:
	ZXDataFile(void);
	~ZXDataFile(void);

	// ����ת��
	// ��ȡ����
	static bool Convert(char *inputFileName, DataFormat format);

private:
	// �����ļ���չ�����ж��ļ�����
	static DataFormat GetFormatByFileName(char *fileName);
};

