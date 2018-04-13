//
//  Vector3.h
//  XYZ
//  ��ά�ռ䳣����ģ��C++ʵ�֡���װ����ά�ռ������ĳ��ó�Ա�뷽����
//
//  Created by ������(duzixi[at]gmail[dot]com) on 18-4-7.
//  Copyright (c) 2018�� www.duzixi.com All rights reserved.
//

#pragma once

using namespace std;

namespace XYZ {

	template <class T>
	class Vector3
	{
	public:
		T x;
		T y;
		T z;
		// ���캯�� ==============================
		Vector3();
		Vector3(T _x, T _y);
		Vector3(T _x, T _y, T _z);
		// ��������
		~Vector3();

		// ����====================================
		// ��������
		/* �����������ϵ���£�
		y
		^
		|
		|   ����ͼ        z�ᴹֱ��Ļ����
		|
		o-----------> x
		*/
		// (0, -1, 0)
		static Vector3<T> back;
		// (0, 0, -1)
		static Vector3<T> down;
		// (0, 1, 0)
		static Vector3<T> forward;
		// (0, 1, 0)
		static Vector3<T> fwd;
		// (-1, 0, 0)
		static Vector3<T> left;
		// (1, 1, 1)
		static Vector3<T> one;
		// (1, 0, 0)
		static Vector3<T> right;
		// (0, 0, 1)
		static Vector3<T> up;
		// (0, 0, 0)
		static Vector3<T> zero;

		// ģ��ƽ��
		T sqrMagnitude;

		// ģ
		T magnitude;

		// �෽�� ===============================

		// ���
		static T Dot(Vector3<T> lhs, Vector3<T> rhs);
		// ���
		static Vector3<T> Cross(Vector3<T> lhs, Vector3<T> rhs);
		// ����
		static T Distance(Vector3<T> a, Vector3<T> b);
		// ��λ��
		static Vector3<T> Normalize(Vector3<T> value);

		// �нǴ�С���Ƕȣ�
		static T Angle(Vector3<T> from, Vector3<T> to);
		// �нǴ�С�����ȣ�
		static T AngleBetween(Vector3<T> from, Vector3<T> to);

		// ���ֵ(X,Y,Z��ȡ���)
		static Vector3<T> Max(Vector3<T> lhs, Vector3<T> rhs);

		// ��Сֵ(X,Y,Z��ȡ��С)
		static Vector3<T> Min(Vector3<T> lhs, Vector3<T> rhs);

		// ����ͶӰ
		static Vector3<T> Project(Vector3<T> vector, Vector3<T> onNormal);

		// ����
		static Vector3<T> Scale(Vector3<T> a, Vector3<T> b);

		// ��Ա���� ==============================

		// ��λ�������ı���������
		Vector3<T> normalized();

		// ����
		void Scale(Vector3<T> scale);

		// ����
		void Set(T _x, T _y, T _z);

		// �����ַ���
		string ToString();


		// ��������� ==========================

		// �Ƚ��Ƿ����
		bool operator==(const Vector3<T> &rhs) const;
		// �Ƚ��Ƿ����
		bool operator!=(const Vector3<T> &rhs) const;

	};

	// ���������

	template <class T>
	Vector3<T> operator+(const Vector3<T> &a, const Vector3<T> &b);

	template <class T>
	Vector3<T> operator-(const Vector3<T> &a, const Vector3<T> &b);

	template <class T>
	Vector3<T> operator*(const T d, const Vector3<T> &a);

	template <class T>
	Vector3<T> operator* (const Vector3<T> &a, const T d);

	template <class T>
	Vector3<T> operator/ (const Vector3<T> &a, const T d);

}