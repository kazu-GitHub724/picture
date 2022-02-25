#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//�摜�T�C�Y���`����
#define X_SIZE 640
#define Y_SIZE 480

//�ǂݍ��݂ƕۑ��p�̃t�@�C���p�X��p��
char read_path[500];
char save_path[500];

//���͂�RGB�l��p��
unsigned char r_in[Y_SIZE][X_SIZE], g_in[Y_SIZE][X_SIZE], b_in[Y_SIZE][X_SIZE];

//�O���C�摜�̏o�͐�̔z��
unsigned char color[Y_SIZE][X_SIZE];
unsigned char hanten[Y_SIZE][X_SIZE];



//�֐��̃v���g�^�C�v��錾����
void read_img(char* read_path, unsigned char r_in[Y_SIZE][X_SIZE], unsigned char g_in[Y_SIZE][X_SIZE], unsigned char b_in[Y_SIZE][X_SIZE]);
void gray_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void sayu_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void zyouge_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void sepia_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void moza_img();
void save_img(char* save_path, unsigned char img[Y_SIZE][X_SIZE]);

//���C���ƂȂ�֐�
int main()
{
	int cmd;
	while (1)
	{
		//���͉摜�̓ǂݍ���
		read_img(read_path, r_in, g_in, b_in);

		printf("���������\n");
		printf("1 = �O���C�X�P�[�����@  -1 = �I�� \n");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			//�O���C�X�P�[����
			gray_img(r_in, g_in, b_in, color);
			save_img(save_path, color);
			break;
		case 2:
			save_img(save_path, color);
			break;
		}
		if (cmd == -1)
		{
			break;
		}
	}
	
	////�o�͉摜�̕ۑ�
	//save_img(save_path,color);

}

//���͉摜�̓ǂݍ���
void read_img(char* read_path, unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE])
{
	int i, j;

	//�t�@�C�����߂̃t�@�C����p��
	printf("�ǂݍ��ރt�@�C��-->");
	//�W�����͂��o�b�t�@�Ɋi�[����
	scanf("%s", read_path);

	FILE* fp;

	//�t�@�C�����J��
	fp = fopen(read_path, "rb");

	//�����C�t�@�C���������Ƃ��ɏI��������
	if (fp == NULL)
	{
		printf("�t�@�C�������݂��܂���", read_path);
		exit(-1);
	}

	//�摜������RGB�l�̎擾
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			r[j][i] = fgetc(fp);
			g[j][i] = fgetc(fp);
			b[j][i] = fgetc(fp);
		}
	}
	//�t�@�C�������
	fclose(fp);
}

//�O���C��
void gray_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;

	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			img[j][i] = (unsigned char)(0.30 * r[j][i] + 0.59 * g[j][i] + 0.11 * b[j][i]);
		}
	}
}

//�Z�s�A����
//void gray_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE])
//{
//	int i, j;
//
//	for (j = 0; j < Y_SIZE; j++)
//	{
//		for (i = 0; i < X_SIZE; i++)
//		{
//			img[j][i] = (unsigned char)(0.30 * r[j][i] + 0.59 * g[j][i] + 0.11 * b[j][i]);
//		}
//	}
//}


//���E���]
//void sayu_img(struct imgptr Image, int h, int w)
//{
//	int x, y;
//	for (y = 0; y < h; y++)
//		for (x = 0; x < w / 2; x++) {
//			int tmp = Image.w[y][x];
//			Image.w[y][x] = Image.w[y][w - x - 1];
//			Image.w[y][w - x - 1] = tmp;
//		}
//}

////�㉺���]
//void sayu_img(struct imgptr Image, int h, int w)
//{
//	int x, y;
//	for (y = 0; y < h / 2; y++)
//	{
//		for (x = 0; x < w; x++) {
//			int tmp = Image.w[y][x];
//			Image.w[y][x] = Image.w[h - y - 1][x];
//			Image.w[h - y - 1][x] = tmp;
//		}
//	}
//}

//���U�C�N
//void moza_img()
//{
	//for (i = 0; i < Y_SIZE / s; i++) // �e�u���b�N�Ƀ��U�C�N����
	//	for (j = 0; j < X_SIZE / s; j++) {
	//
	//		rr = 0;
	//		gg = 0;
	//		bb = 0;
	//
	//		for (k = 0; k < s; k++)// �u���b�N���s�N�Z���̂q�f�a�������v
	//			for (l = 0; l < s; l++) {
	//
	//				bb += lpBMP[(j * s + l + (i * s + k) * xSize) * 3];
	//				gg += lpBMP[(j * s + l + (i * s + k) * xSize) * 3 + 1];
	//				rr += lpBMP[(j * s + l + (i * s + k) * xSize) * 3 + 2];
	//
	//			}
	//
	//		r = (BYTE)(rr / (s * s)); // �u���b�N�̂q�f�a�����v�Z
	//		g = (BYTE)(gg / (s * s));
	//		b = (BYTE)(bb / (s * s));
	//
	//		for (k = 0; k < s; k++) // �u���b�N���s�N�Z���ɐF��t����
	//			for (l = 0; l < s; l++) {
	//
	//				lpBMP[(j * s + l + (i * s + k) * xSize) * 3] = b;
	//				lpBMP[(j * s + l + (i * s + k) * xSize) * 3 + 1] = g;
	//				lpBMP[(j * s + l + (i * s + k) * xSize) * 3 + 2] = r;
	//
	//			}
	//
	//	}
//}
//�o�͉摜�̕ۑ�
void save_img(char* save_path, unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;

	FILE* fp;

	printf("�ǂ̃t�@�C���ɕۑ����܂����H-->");
	scanf("%s", save_path);

	//�t�@�C�����J��
	fp = fopen(save_path, "wb");

	////�����C�t�@�C���������Ƃ��ɏI��������
	if (fp == NULL)
	{
		printf("�t�@�C�������݂��܂���", save_path);
		exit(-1);
	}
	//�摜��RGB�l���t�@�C���ɕۑ�����
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			fputc(img[j][i], fp);
		}
	}
	//�t�@�C�������
	fclose(fp);
	printf("�ۑ����܂���\n");
}