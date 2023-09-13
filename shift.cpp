/*
Filename: readppm.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Reads a ppm file fg and bg and transposes them with a given rowshift
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // get the foreground filename
  string fgName;
  cout << "Foreground file: ";
  cin >> fgName;

  // get the background filename
  string bgName;
  cout << "Background file: ";
  cin >> bgName;

  // get the row shift value
  int rowShift;
  cout << "Row shift: ";
  cin >> rowShift;

  // get the col shift value
  int colShift;
  cout << "Column shift: ";
  cin >> colShift;

  // open the file for reading
  ifstream fgImage(fgName);

  // open background file
  ifstream bgImage(bgName);

  // get the output file
  string outName;
  cout << "Output file: ";
  cin >> outName;

  // make sure input files opened
  if (!bgImage || !fgImage)
  {
    cout << "Error: Input file not found" << endl;
    return 1;
  }

  // open the output file
  ofstream outImage(outName);

  // read header
  string fgHeader, bgHeader;
  fgImage >> fgHeader;
  bgImage >> bgHeader;

  // read bgWidth and bgHeight
  int bgWidth, bgHeight;
  int fgWidth, fgHeight;
  fgImage >> fgWidth >> fgHeight;
  bgImage >> bgWidth >> bgHeight;

  // make sure the foreground isn't bigger than the background
  if (rowShift + fgHeight > bgHeight ||
      colShift + fgWidth > bgWidth)
  {
    cout << "Error: The foreground goes past the background" << endl;
    return 1;
  }

  // read max pixel value
  int maxValue;
  fgImage >> maxValue;
  bgImage >> maxValue;

  // Output main data to output file
  outImage << fgHeader << endl;
  outImage << bgWidth << " " << bgHeight << endl;
  outImage << maxValue << endl;

  // read in per pixel and row/col
  int fred, fgreen, fblue, bred, bgreen, bblue;

  for (int row = 0; row < bgHeight; row++)
  {
    for (int col = 0; col < bgWidth; col++)
    {
      // read the pixel data
      if ((row >= rowShift) && (row < rowShift + fgHeight) &&
          (col >= colShift) && (col < colShift + fgWidth))
      {
        fgImage >> fred >> fgreen >> fblue;
      }
      else
      {
        fred = 0;
        fgreen = maxValue;
        fblue = 0;
      }
      bgImage >> bred >> bgreen >> bblue;

      // determine which pixel to save
      int red = fred,
          green = fgreen,
          blue = fblue;
      if (fred == 0 && fgreen == maxValue && fblue == 0)
      {
        red = bred;
        green = bgreen;
        blue = bblue;
      }

      // write it out to the file
      outImage << red << " " << green << " " << blue << " ";
    }
  }

  cout << "Image saved to " << outName << endl
       << endl;

  return 0;
}
