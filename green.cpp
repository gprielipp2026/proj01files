/*
Filename: readppm.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Reads a ppm file fg and bg and transposes them
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

  // open the file for reading
  ifstream fgImage(fgName);

  // open background file
  ifstream bgImage(bgName);

  // get the output file
  string outName;
  cout << "Output file: ";
  cin >> outName;

	// make sure input files opened
	if(!bgImage || ! fgImage)
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

  // read width and height
  int width, height;
  int wCheck, hCheck;
  fgImage >> width >> height;
  bgImage >> wCheck >> hCheck;

  // make sure the files match
  if (width != wCheck || height != hCheck)
  {
    cout << "Error: Images have different sizes" << endl;
    return 1;
  }

  // read max pixel value
  int maxValue;
  fgImage >> maxValue;
	bgImage >> maxValue;

  // Output main data to output file
  outImage << fgHeader << endl;
  outImage << width << " " << height << endl;
  outImage << maxValue << endl;

  // read in per pixel and row/col
  int row = 0;
  int fred, fgreen, fblue, bred, bgreen, bblue;

  while (row < height)
  {
    int col = 0;
    while (col < width)
    {
      // read the pixel data
      fgImage >> fred >> fgreen >> fblue;
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
      
      // move to the next col
      col += 1;
    }

    // move to next row
    row += 1;
  }

  cout << "Image saved to " << outName << endl << endl;

  return 0;
}
