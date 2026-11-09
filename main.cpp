#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

vector <int> goodColor(int red, int green, int blue, int& sRed, int& sGreen, int& sBlue);
int newColor(fstream file, vector <int> sRGB);


int main()
{
    int colorBlindness;
    char level;
    int red;
    int green;
    int blue;
    int sRed;
    int sGreen;
    int sBlue;
    vector <int> RGB;

    do{
        cout << "Enter the number associated with the type of blindness you want info on: " << endl;
        cout << "Enter 1 for red-green color blindness, 2 for blue-yellow color blindness, 3 for complete color blindness. " << endl; 
        cin >> colorBlindness;
    }while(colorBlindness < 1 || colorBlindness > 3);
    
    do{
        cout << "Enter either I (intense) or M (mild) to indicate the severity of the blindness. " << endl;
        cin >> level;
    }while(level != 'I' && level != 'M');

    do{
        cout << "Enter the color you would like to center in your program using integers in RGB formatting (RGB values range from 0-255). Example: 000 (enter) 000 (enter) 000 (enter)" << endl;
        cin >> red;
        if(red <= 255 && red >= 0){
        RGB.push_back(red);
    }
        cin >> green;
        if(green <= 255 && green >= 0){
        RGB.push_back(green);
    }
        cin >> blue;
        if(blue <= 255 && blue >= 0){
        RGB.push_back(blue);
    }
    }while(red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255);

    if(colorBlindness == 1){
        cout << "Avoid using red and green shades next to each other, blue and purple do not work well together but paired with other colors will stand out.\nPlace blue/purple near green/red for maximum visibility." << endl;
    }
    else if(colorBlindness == 2){
        cout << "Avoid placing warm colors (red, orange, yellow) near each other, and vice versa for cold colors (blue, green, purple).\nDo not use analogous color schemes, orange and blue is the most identifiable pallet." << endl;
    }
    else{
        cout << "Avoid using colors that share the same value (light/dark colors).\nConvert/use a grayscale pallet for maximum visibility." << endl;
    }
    if(level == 'M'){
        cout << "You may still use the colors listed to avoid, if they are significantly different in shade." << endl;
    }
    if(level == 'I'){
        cout << "It is optimal to avoid all colors that are difficult to see, unless you are using a grayscale pallet." << endl;
    }
    goodColor(red, green, blue, sRed, sGreen, sBlue);
    cout << "A potential complimentary color to use would be: " << sRed << " " << sGreen << " " << sBlue << endl;

  return 0;
}

vector <int> goodColor(int red, int green, int blue, int& sRed, int& sGreen, int& sBlue){
  vector <int> sRGB;
  bool validColor;
  vector<int> randomList;
  int currentNumber;

  do{
    int sRed;
    int sGreen;
    int sBlue;
  newColor();
  sRGB.push_back(sRed);
  newColor();
  sRGB.push_back(sGreen);
  newColor();
  sRGB.push_back(sBlue);

  if(sRGB[0] == red || sRGB[1] == green || sRGB[2] == blue){
    validColor = false;
  }
  else{
    validColor = true;
  }

}while(validColor == false);
return sRGB;
}

int newColor(){
  vector <int> randomValues;
  int value;
  ifstream file;
  while(file >> value){
    randomValues.push_back(value);
  }
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<size_t> distr(0, randomValues.size()-1);
  size_t random_index = distr(gen);
  int random_value = randomValues[random_index];
  return random_value;
}



