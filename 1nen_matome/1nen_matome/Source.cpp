#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//画像サイズを定義する
#define X_SIZE 640
#define Y_SIZE 480

//読み込みと保存用のファイルパスを用意
char read_path[500];
char save_path[500];

//入力のRGB値を用意
unsigned char r_in[Y_SIZE][X_SIZE], g_in[Y_SIZE][X_SIZE], b_in[Y_SIZE][X_SIZE];

//グレイ画像の出力先の配列
unsigned char color[Y_SIZE][X_SIZE];
unsigned char hanten[Y_SIZE][X_SIZE];



//関数のプロトタイプを宣言する
void read_img(char* read_path, unsigned char r_in[Y_SIZE][X_SIZE], unsigned char g_in[Y_SIZE][X_SIZE], unsigned char b_in[Y_SIZE][X_SIZE]);
void gray_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void sayu_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void zyouge_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void sepia_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
//void moza_img();
void save_img(char* save_path, unsigned char img[Y_SIZE][X_SIZE]);

//メインとなる関数
int main()
{
	int cmd;
	while (1)
	{
		//入力画像の読み込み
		read_img(read_path, r_in, g_in, b_in);

		printf("処理を入力\n");
		printf("1 = グレイスケール化　  -1 = 終了 \n");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			//グレイスケール化
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
	
	////出力画像の保存
	//save_img(save_path,color);

}

//入力画像の読み込み
void read_img(char* read_path, unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE])
{
	int i, j;

	//ファイルためのファイルを用意
	printf("読み込むファイル-->");
	//標準入力をバッファに格納する
	scanf("%s", read_path);

	FILE* fp;

	//ファイルを開く
	fp = fopen(read_path, "rb");

	//もし，ファイルが無いときに終了させる
	if (fp == NULL)
	{
		printf("ファイルが存在しません", read_path);
		exit(-1);
	}

	//画像内からRGB値の取得
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			r[j][i] = fgetc(fp);
			g[j][i] = fgetc(fp);
			b[j][i] = fgetc(fp);
		}
	}
	//ファイルを閉じる
	fclose(fp);
}

//グレイ化
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

//セピア調化
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


//左右反転
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

////上下反転
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

//モザイク
//void moza_img()
//{
	//for (i = 0; i < Y_SIZE / s; i++) // 各ブロックにモザイク処理
	//	for (j = 0; j < X_SIZE / s; j++) {
	//
	//		rr = 0;
	//		gg = 0;
	//		bb = 0;
	//
	//		for (k = 0; k < s; k++)// ブロック内ピクセルのＲＧＢ成分合計
	//			for (l = 0; l < s; l++) {
	//
	//				bb += lpBMP[(j * s + l + (i * s + k) * xSize) * 3];
	//				gg += lpBMP[(j * s + l + (i * s + k) * xSize) * 3 + 1];
	//				rr += lpBMP[(j * s + l + (i * s + k) * xSize) * 3 + 2];
	//
	//			}
	//
	//		r = (BYTE)(rr / (s * s)); // ブロックのＲＧＢ成分計算
	//		g = (BYTE)(gg / (s * s));
	//		b = (BYTE)(bb / (s * s));
	//
	//		for (k = 0; k < s; k++) // ブロック内ピクセルに色を付ける
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
//出力画像の保存
void save_img(char* save_path, unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;

	FILE* fp;

	printf("どのファイルに保存しますか？-->");
	scanf("%s", save_path);

	//ファイルを開く
	fp = fopen(save_path, "wb");

	////もし，ファイルが無いときに終了させる
	if (fp == NULL)
	{
		printf("ファイルが存在しません", save_path);
		exit(-1);
	}
	//画像のRGB値をファイルに保存する
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			fputc(img[j][i], fp);
		}
	}
	//ファイルを閉じる
	fclose(fp);
	printf("保存しました\n");
}