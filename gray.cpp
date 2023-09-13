/*
Filename: readppm.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Reads a ppm file and outputs a grayscale image
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // get the input filename
  string filename;
  cout << "Input file: ";
  cin >> filename;

  // get the output filename
  string outFilename;
  cout << "Output file: ";
  cin >> outFilename;

  // open the file for reading
  ifstream imageData(filename);

  if(!imageData)
  {
    cout << "Error: Input file not found" << endl;
    return 1;
  }

  // open output file
  ofstream imageGray(outFilename);

  // read header
  string fileHeader;
  imageData >> fileHeader;

  // read width and height
  int width, height;
  imageData >> width >> height;

  // read max pixel value
  int maxValue;
  imageData >> maxValue;

  // Output main data to output file
  imageGray << fileHeader << endl;
  imageGray << width << " " << height << endl;
  imageGray << maxValue << endl;

  // read in per pixel and row/col
  int row = 0;
  int red, green, blue, grayscale;

  while (row < height)
  {
    int col = 0;
    while (col < width)
    {
      // read the pixel data
      imageData >> red >> green >> blue;

      // calculate the grayscale value
      grayscale = (red + green + blue) / 3;

      // write it out to the file
      imageGray << grayscale << " " << grayscale << " " << grayscale << " ";
      
      // move to the next col
      col += 1;
    }

    // new line in the grayscale
    // imageGray << endl;

    // move to next row
    row += 1;
  }

  cout << "Image saved to " << outFilename << endl << endl;

  return 0;
}
