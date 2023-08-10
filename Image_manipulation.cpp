#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function prototypes
void displayMenu();
void resizeImage(const Mat &inputImage, Mat &outputImage, int width, int height);
void cropImage(const Mat &inputImage, Mat &outputImage, int x, int y, int width, int height);
void applyGaussianBlur(const Mat &inputImage, Mat &outputImage, int kernelSize);

int main()
{
    // Load the input image
    Mat inputImage = imread("input.jpg");

    // Check if the image was loaded successfully
    if (inputImage.empty())
    {
        cout << "Failed to load the image!" << endl;
        return -1;
    }

    // Display the menu
    int choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        Mat outputImage;

        switch (choice)
        {
        case 1:
        {
            // Resize image
            int width, height;
            cout << "Enter the new width: ";
            cin >> width;
            cout << "Enter the new height: ";
            cin >> height;
            resizeImage(inputImage, outputImage, width, height);
            break;
        }
        case 2:
        {
            // Crop image
            int x, y, width, height;
            cout << "Enter the starting x-coordinate: ";
            cin >> x;
            cout << "Enter the starting y-coordinate: ";
            cin >> y;
            cout << "Enter the width: ";
            cin >> width;
            cout << "Enter the height: ";
            cin >> height;
            cropImage(inputImage, outputImage, x, y, width, height);
            break;
        }
        case 3:
        {
            // Apply Gaussian blur
            int kernelSize;
            cout << "Enter the kernel size: ";
            cin >> kernelSize;
            applyGaussianBlur(inputImage, outputImage, kernelSize);
            break;
        }
        case 4:
            // Exit the program
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }

        // Display the processed image
        imshow("Processed Image", outputImage);
        waitKey(0);

    } while (true);

    return 0;
}

void displayMenu()
{
    cout << "Image Processing Menu" << endl;
    cout << "---------------------" << endl;
    cout << "1. Resize Image" << endl;
    cout << "2. Crop Image" << endl;
    cout << "3. Apply Gaussian Blur" << endl;
    cout << "4. Exit" << endl;
}

void resizeImage(const Mat &inputImage, Mat &outputImage, int width, int height)
{
    resize(inputImage, outputImage, Size(width, height));
}

void cropImage(const Mat &inputImage, Mat &outputImage, int x, int y, int width, int height)
{
    Rect roi(x, y, width, height);
    outputImage = inputImage(roi);
}

void applyGaussianBlur(const Mat &inputImage, Mat &outputImage, int kernelSize)
{
    GaussianBlur(inputImage, outputImage, Size(kernelSize, kernelSize), 0);
}