#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	//declare variables
	string MagicPPM;
	int imageX;
	int imageY;
	int colorScale;
	int imageRed;
	int imageGreen;
	int imageBlue;

	// open input file
	ifstream fin("color_image.ppm");

	//test input file
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//Create output file
	ofstream fout("grayscale_image.ppm");

	//Get MagicPPM, Image size, and colorscale numbers
	fin >> MagicPPM;
	fin >> imageX;
	fin >> imageY;
	fin >> colorScale;

	//Set MagicPPM const, image size for output file
	fout << MagicPPM << endl;
	fout << imageX << " " << imageY << endl;
	fout << colorScale << endl;

	//read input file numbers and output new grayscale numbers
	while (fin >> imageRed >> imageGreen >> imageBlue) {
		fout << int(imageRed * 0.3 + imageGreen * 0.59 + imageBlue * 0.11) << endl;
		fout << int(imageRed * 0.3 + imageGreen * 0.59 + imageBlue * 0.11) << endl;
		fout << int(imageRed * 0.3 + imageGreen * 0.59 + imageBlue * 0.11) << endl;
	}

	//close files and exit
	fout.close();
	fin.close();
	return 0;

}