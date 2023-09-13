/*
Filename: readppm.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Reads a ppm file and outputs the pixel values and other data
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

  // open the file for reading
  ifstream imageData(filename);

  if(!imageData) return 1; // is file open?

  // read header
  string fileHeader;
  imageData >> fileHeader;

  // read width and height
  int width, height;
  imageData >> width >> height;

  // read max pixel value
  int maxValue;
  imageData >> maxValue;

  // Output main data to screen
  cout << fileHeader << endl;
  cout << "width = " << width << ", height = " << height << endl;
  cout << "max value = " << maxValue << endl;

  // read in per pixel and row/col
  int row = 0;
  int red, green, blue;

  while (row < height)
  {
    // report which row I'm reading from
    cout << "*** row " << row << " ***" << endl;

    int col = 0;
    while (col < width)
    {
      // read the pixel data
      imageData >> red >> green >> blue;

      // report data that was read
      cout << "row " << row << ", col " << col
           << ": r" << red << " g" << green
           << " b" << blue << endl;
      
      // move to the next col
      col += 1;
    }

    // move to next row
    row += 1;
  }

  return 0;
}
