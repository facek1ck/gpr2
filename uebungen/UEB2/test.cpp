#ifdef TESTS

#include <iostream>
#include "asciiimage.h"
#include <gtest/gtest.h>

TEST(CONSTRUCTOR, SET_WIDTH_AND_HEIGHT)
{
	myAscii mandelbrot(3, 5);
	ASSERT_EQ(mandelbrot.width, 3);
	ASSERT_EQ(mandelbrot.height, 5);
}

TEST(CONSTRUCTOR, INIT_PIC)
{
	myAscii mandelbrot(3, 5);
	for (int i = 0; i<mandelbrot.width; ++i)
		for (int j = 0; j<mandelbrot.height; ++j)
			ASSERT_EQ(mandelbrot.pic[i][j], ' ');
}

TEST(SET_PIX, SET_COLOR_0)
{
	myAscii mandelbrot(3, 5);
	mandelbrot.setPix(0, 0, 0);
	ASSERT_EQ(mandelbrot.pic[0][0], ' ');
}

TEST(SET_PIX, SET_COLOR_35)
{
	myAscii mandelbrot(3, 5);
	mandelbrot.setPix(0, 0, 35);
	ASSERT_EQ(mandelbrot.pic[0][0], 'n');
}

TEST(SET_PIX, SET_COLOR_69)
{
	myAscii mandelbrot(3, 5);
	mandelbrot.setPix(0, 0, 69);
	ASSERT_EQ(mandelbrot.pic[0][0], '$');
}

TEST(SET_PIX, SET_COLOR_NEGATIVE)
{
	myAscii mandelbrot(3, 5);
	mandelbrot.setPix(0, 0, -1);
	ASSERT_EQ(mandelbrot.pic[0][0], ' ');
}

TEST(SET_PIX, SET_COLOR_POSITIVE)
{
	myAscii mandelbrot(3, 5);
	mandelbrot.setPix(0, 0, 100);
	ASSERT_EQ(mandelbrot.pic[0][0], '$');
}

TEST(SHOW, DOES_PRINT)
{
	myAscii mandelbrot(3, 5);
	testing::internal::CaptureStdout();
	mandelbrot.show();
	std::string output = testing::internal::GetCapturedStdout();
	std::cout << output;
	ASSERT_EQ(output, "   \n   \n   \n   \n   \n");
}

TEST(SHOW, DOES_PRINT_EXACTLY)
{
	myAscii mandelbrot(80, 25);

	double x0 = -3;
	double y0 = -1.5;
	double x1 = 1;
	double y1 = 1.5;
	int maxi = 50;

	//x und y Koordinate im imaginären Bild
	double x;
	double y;

	//Skaliere für jeden Punkt der Computergrafik den dazu gehörigen Punkt der imaginären Grafik
	for (int s = 0; s<80; s++) {
		x = x0 + (x1 - x0) / ((double)80)*(double)s;
		for (int t = 0; t<25; t++) {
			y = y0 + (y1 - y0) / ((double)25)*(double)t;

			double zr = 0;
			double zi = 0;
			int i;

			//Berechnung der Farbwerte
			for (i = 0; i < maxi; ++i) {
				// calculate next iteration
				// For the interested reader: z=zr+i*zi and c=x+i*y are complex numbers
				// In the next row we calculate z * z + c and check whether |z| > 2
				double nextzr = zr * zr - zi * zi + x;
				double nextzi = 2 * zr * zi + y;
				// are we done?
				if (nextzr * nextzr + nextzi * nextzi > 4) {
					// TODO: set pixel to i % 70
					// Insert here code to draw
					//cout << "Pixel: " << t << "," << s << " ist " << i << "|";
					break;
				}
				zr = nextzr;
				zi = nextzi;
			}

			int color = i % 70;
			mandelbrot.setPix(s, t, color);
		}
	}

	testing::internal::CaptureStdout();
	mandelbrot.show();
	std::string output = testing::internal::GetCapturedStdout();

	std::string expected = "                                  ..............................................\n                                ................................................\n                             ............'''''''''''''''''''....................\n                            .......'''''''''''''''''````^^^```''''..............\n                          .....''''''''''''''''``````^^\",<:,,`````''''..........\n                         ...''''''''''''''''```````^^^\":;n{l:\"^^````'''''.......\n                        ..'''''''''''''''```````^^\"\"\",:-mmmm>:,\"^^^```'''''.....\n                       .'''''''''''''''`````^^\",n+l;ivm]{mm}+m![:,,],^`''''''...\n                      .''''''''''''```^^^^^^\"\",:Immmmmmmmmmmmmmmmmm>:^^`''''''..\n                     .''''''''```^,;\"\"\"\"\"\",,,:lnmmmmmmmmmmmmmmmmmmmm:,^``''''''.\n                     '''``````^^^\",I~?!ixil;;l{mmmmmmmmmmmmmmmmmmmmm<:\"``'''''''\n                     '`````^^^^^,:I~[mmmmmmmf-mmmmmmmmmmmmmmmmmmmmmm!,^```''''''\n                     ^^\"\",,\"\",,;immmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm<,\"^```''''''\n                     ^^\"\",,\"\",,;immmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm<,\"^```''''''\n                     '`````^^^^^,:I~[mmmmmmmf-mmmmmmmmmmmmmmmmmmmmmm!,^```''''''\n                     '''``````^^^\",I~?!ixil;;l{mmmmmmmmmmmmmmmmmmmmm<:\"``'''''''\n                     .''''''''```^,;\"\"\"\"\"\",,,:lnmmmmmmmmmmmmmmmmmmmm:,^``''''''.\n                      .''''''''''''```^^^^^^\"\",:Immmmmmmmmmmmmmmmmm>:^^`''''''..\n                       .'''''''''''''''`````^^\",n+l;ivm]{mm}+m![:,,],^`''''''...\n                        ..'''''''''''''''```````^^\"\"\",:-mmmm>:,\"^^^```'''''.....\n                         ...''''''''''''''''```````^^^\":;n{l:\"^^````'''''.......\n                          .....''''''''''''''''``````^^\",<:,,`````''''..........\n                            .......'''''''''''''''''````^^^```''''..............\n                             ............'''''''''''''''''''....................\n                                ................................................\n";

	ASSERT_EQ(output, expected);
}

#endif