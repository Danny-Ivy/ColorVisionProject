#include <iostream>
using namespace std;

int main()
{
    int color;
    char level;

    do{
        cout << "Enter the number associated with the type of blindness you want info on: " << endl;
        cout << "Enter 1 for red-green color blindness, 2 for blue-yellow color blindness, 3 for complete color blindness. " << endl; 
        cin >> color;
        cout << "Enter either I (intense) or M (mild) to indicate the severity of the blindness. " << endl;
        cin >> level;
    }while(color != 1 && color != 2 && color != 3 && level != 'I' && level != 'M');
    
    if(color == 1){
        cout << "Avoid using red and green shades next to each other, blue and purple do not work well together but paired with other colors will stand out.\nPlace blue/purple near green/red for maximum visibility." << endl;
    }
    else if(color == 2){
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

  return 0;
}


