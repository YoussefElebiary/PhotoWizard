//*-----------------------------------------------------------------------------------------------*//
//Purpose     :     This is a GUI application that can apply different filters to images
//Authors     :     Youssef Ahmed Mahmoud Mohamed Elebiary   -   20231208   -   S25
//                  Nagham Wael Mohamed   -   20231189   -   S25
//                  Zainab Mostafa Mohammad   -   20231071   -   S25
//Who did what:     Youssef → GUI/Invert/Rotate/Frame/Blur
//                  Nagham → B&W/Flip/Crop/Reszie/DarkRed/InfraRed/Purple/Sunlight/TV
//                  Zainab → GrayScale/Merge/Darken&Lighten/DetectEdges/OilPainting/Skew
//Demo Video  :     https://www.youtube.com/watch?v=htMccaki04Q
//*-----------------------------------------------------------------------------------------------*//



#include "babyphotoshop.h"
#include "ui_babyphotoshop.h"
#include "Image_class.h"
#include <QColor>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <vector>
#include <cmath>

#define ll long long


QString fileName;
Image image_i;
Image image_t;
Image image_prev;
const std::string temp = "temp.jpg";
QString Qtemp = "temp.jpg";


BabyPhotoshop::BabyPhotoshop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhotoWizard)
{
    ui->setupUi(this);
}

BabyPhotoshop::~BabyPhotoshop()
{
    QFile tempFile(Qtemp);
    if (tempFile.exists()) {
        tempFile.remove();
    }
    delete ui;
}

void BabyPhotoshop::on_load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.tga *.jpeg *.bmp)");
    QLabel* imageLabel = findChild<QLabel*>("image1");
    if (imageLabel) {
        // Load image
        QPixmap image(fileName);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);

        image_i.loadNewImage(fileName.toStdString());
    }
    image_t = image_i;
    image_prev = image_t;
    image_t.saveImage("temp.jpg");
}


void BabyPhotoshop::on_invert_clicked()
{
    std::string path = fileName.toStdString();
    int w = image_t.width, h = image_t.height;
    image_prev = image_t;
    //Looping over each pixel
    for (int i = 0; i < w; ++i) {           //Width
        for (int j = 0; j < h; ++j) {       //Height
            for (int k = 0; k < 3; ++k) {   //Channels
                image_t(i, j, k) = 255 - image_t(i, j, k);
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_b_w_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image_t(i, j, k);
            }
            avg /= 3; // Calculate average

            unsigned int new_pixel;
            (avg > (255/2)) ? new_pixel = 255 : new_pixel = 0;
            image_t(i, j, 0) = new_pixel;
            image_t(i, j, 1) = new_pixel;
            image_t(i, j, 2) = new_pixel;
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}

void BabyPhotoshop::on_gray_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    for (int i = 0 ; i < w; ++i){
        for (int j = 0 ; j < h; ++j){

            unsigned int avg = 0;  // Initializing average value.
            for (int k = 0 ; k < image_t.channels ; ++k){
                avg +=image_t (i,j,k);
            }
            avg /= 3;  // Calculating the average.

            for (int k = 0 ; k < image_t.channels ; ++k){
                image_t(i,j,k) = avg ;  // setting the three intensities (RGB channels) to average value.
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_light_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    int LightedPixel;
    for (int i = 0 ; i < w; ++i){
        for (int j = 0 ; j < h; ++j){
            for (int k = 0 ; k < image_t.channels ; ++k){

                unsigned char PixelValue;  //ensuring that range of pixel value from 0 to 255.
                PixelValue = image_t.getPixel(i , j , k);  //looping over each pixel in the image.
                LightedPixel = PixelValue * 1.5;  //calculating lighted pixel.
                if (LightedPixel < 0){
                    LightedPixel = 0;
                }
                else if (LightedPixel > 255){
                    LightedPixel = 255;
                }
                image_t.setPixel(i , j , k , LightedPixel);  //replace native pixels with lighted one.
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_dark_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    int DarkenedPixel;
    for (int i = 0 ; i < w; ++i){
        for (int j = 0 ; j < h; ++j ){
            for (int k = 0 ; k < 3 ; ++k){

                unsigned char PixelValue;   //ensuring that range of pixel value from 0 to 255.
                PixelValue = image_t.getPixel (i,j,k);  //looping over each pixel in the image.
                DarkenedPixel = PixelValue * 0.5; //calculating darkened pixel.
                if (DarkenedPixel < 0){
                    DarkenedPixel = 0;
                }
                else if (DarkenedPixel > 255){
                    DarkenedPixel = 255;
                }
                image_t.setPixel(i,j,k,DarkenedPixel); //replace native pixels with darkened one.
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_frame_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    //Get color
    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Choose a Color");
    int R = color.red();
    int G = color.green();
    int B = color.blue();
    //Left
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < h; ++j) {
            image_t(i, j, 0) = R;
            image_t(i, j, 1) = G;
            image_t(i, j, 2) = B;
        }
    }
    //Right
    for (int i = w-15; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            image_t(i, j, 0) = R;
            image_t(i, j, 1) = G;
            image_t(i, j, 2) = B;
        }
    }
    //Top
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < 15; ++j) {
            image_t(i, j, 0) = R;
            image_t(i, j, 1) = G;
            image_t(i, j, 2) = B;
        }
    }
    //Bottom
    for (int i = 0; i < w; ++i) {
        for (int j = h-15; j < h; ++j) {
            image_t(i, j, 0) = R;
            image_t(i, j, 1) = G;
            image_t(i, j, 2) = B;
        }
    }
    //Left Inner
    for (int i = 19; i < 24; ++i) {
        for (int j = 0; j < h; ++j) {
            image_t(i, j, 0) = 255;
            image_t(i, j, 1) = 255;
            image_t(i, j, 2) = 255;
        }
    }
    //Right Inner
    for (int i = w-22; i < w-17; ++i) {
        for (int j = 0; j < h; ++j) {
            image_t(i, j, 0) = 255;
            image_t(i, j, 1) = 255;
            image_t(i, j, 2) = 255;
        }
    }
    //Top Inner
    for (int i = 0; i < w; ++i) {
        for (int j = 19; j < 24; ++j) {
            image_t(i, j, 0) = 255;
            image_t(i, j, 1) = 255;
            image_t(i, j, 2) = 255;
        }
    }
    //Bottom Inner
    for (int i = 0; i < w; ++i) {
        for (int j = h-22; j < h-17; ++j) {
            image_t(i, j, 0) = 255;
            image_t(i, j, 1) = 255;
            image_t(i, j, 2) = 255;
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_ir_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            // Extract RGB components
            unsigned int red = image_t(i, j, 0); // Red channel
            unsigned int green = image_t(i, j, 1); // Green channel
            unsigned int blue = image_t(i, j, 2); // Blue channel

            // Calculate brightness (average of RGB values)
            unsigned int avg = (red + green + blue) / 3;

            // Calculate the proportion of red based on brightness
            unsigned int redProportion = 255 - avg;

            // Set pixel values based on brightness
            image_t(i, j, 0) = 200; // Red channel
            image_t(i, j, 1) =redProportion ; // Green channel
            image_t(i, j, 2) = redProportion; // Blue channel
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_dark_red_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            // Get the red channel value and set green and blue channels to zero
            unsigned int redValue = image_t(i, j, 0); // Red channel
            image_t(i, j, 1) = 0; // Green channel (set to zero)
            image_t(i, j, 2) = 0; // Blue channel (set to zero)

            // Set all channels to the red channel value
            image_t(i, j, 0) = redValue;
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_flip_v_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h / 2; ++j) { //divide height by two
            // Swap pixels between top and bottom rows
            for (int k = 0; k < 3; ++k) {
                unsigned int pxl = image_t(i, j, k);
                image_t(i, j, k) = image_t(i, h - 1 - j, k);
                image_t(i, h - 1 - j, k) = pxl;
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_flip_h_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    for (int i = 0; i < w / 2; ++i) { //divide width by two
        for (int j = 0; j < h; ++j) {
            // Swap pixels between left and right columns
            for (int k = 0; k < 3; ++k) {
                unsigned int pxl = image_t(i, j, k);
                image_t(i, j, k) = image_t(w - 1 - i, j, k);
                image_t(w - 1 - i, j, k) = pxl;
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_blur_clicked()
{
    QPixmap image(Qtemp);
    image_prev = image_t;
    QSlider* slider = findChild<QSlider*>("blur_s");
    QLabel* label = findChild<QLabel*>("image2");
    int r = slider->value();
    int w = image_t.width;
    int h = image_t.height;

    //Creating the prefix sum 3D vector
    std::vector<std::vector<std::vector<ll>>> prefix(w, std::vector<std::vector<ll>>(h, std::vector<ll>(3)));
    for (ll i = 1; i < w; ++i) {
        prefix[i][0][0] = image_t(i, 0, 0) + prefix[i-1][0][0];
        prefix[i][0][1] = image_t(i, 0, 1) + prefix[i-1][0][1];
        prefix[i][0][2] = image_t(i, 0, 2) + prefix[i-1][0][2];
    }
    for (ll j = 1; j < h; ++j) {
        prefix[0][j][0] = image_t(0, j, 0) + prefix[0][j-1][0];
        prefix[0][j][1] = image_t(0, j, 1) + prefix[0][j-1][1];
        prefix[0][j][2] = image_t(0, j, 2) + prefix[0][j-1][2];
    }
    for (ll i = 1; i < image_t.width; ++i) {
        for (ll j = 1; j < h; ++j) {
            prefix[i][j][0] = image_t(i, j, 0) + prefix[i-1][j][0] + prefix[i][j-1][0] - prefix[i-1][j-1][0];
            prefix[i][j][1] = image_t(i, j, 1) + prefix[i-1][j][1] + prefix[i][j-1][1] - prefix[i-1][j-1][1];
            prefix[i][j][2] = image_t(i, j, 2) + prefix[i-1][j][2] + prefix[i][j-1][2] - prefix[i-1][j-1][2];
        }
    }
    //Blurring
    int kernel = 2 * r + 1;
    int area = kernel * kernel;
    ll sum = 0;
    int right, left, up, down;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                right = i+r;
                left = i-r-1;
                up = j-r-1;
                down = j+r;
                if (right >= w-1) {
                    right = w-1;
                }
                if (left <= 0) {
                    left = 0;
                }
                if (up <= 0) {
                    up = 0;
                }
                if (down >= h-1) {
                    down = h-1;
                }
                sum = prefix[right][down][k] - prefix[left][down][k] - prefix[right][up][k] + prefix[left][up][k];
                image_t(i, j, k) = sum / area;
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_save_clicked()
{
    QString save_name = QFileDialog::getSaveFileName(this, "Save Image", "", "Image Files (*.png *.jpg *.tga *.jpeg *.bmp)");
    if (!save_name.isEmpty()) {
        std::string path = save_name.toStdString();
        image_t.saveImage(path);
    }
}


void BabyPhotoshop::on_rotate_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    int w = image_t.width, h = image_t.height;
    Image f_image(h, w);

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                f_image(j, w - i - 1, k) = image_t(i, j, k);
            }
        }
    }
    image_t = f_image;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }

}


void BabyPhotoshop::on_sunlight_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    for (int i = 0; i < image_t.width; ++i) {
        for (int j = 0; j < image_t.height; ++j) {
            unsigned int red = image_t(i, j, 0); // Red channel
            unsigned int green = image_t(i, j, 1); // Green channel
            unsigned int blue = image_t(i, j, 2); // Blue channel
            image_t(i, j, 0) = red*0.9;  // red channel
            image_t(i, j, 1) = green*0.9; // Green channel
            image_t(i, j, 2) = blue*0.7;// blue channel
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_tv_clicked()
{
    std::string path = fileName.toStdString();
    image_prev = image_t;
    for (int i = 0; i < image_t.width; ++i) {
        for (int j = 0; j < image_t.height; ++j) {
            if(j%2 == 0) {
                image_t(i, j, 0) = 0;  // red channel
                image_t(i, j, 1) = 0; // Green channel
                image_t(i, j, 2) = 0;// blue channel
            }
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_purple_clicked()
{
    image_prev = image_t;
    for (int i = 0; i < image_t.width; ++i) {
        for (int j = 0; j < image_t.height; ++j) {
            unsigned int red = image_t(i, j, 0); // Red channel
            unsigned int green = image_t(i, j, 1); // Green channel
            unsigned int blue = image_t(i, j, 2); // Blue channel
            image_t(i, j, 0) = red*0.6;  // red channel
            image_t(i, j, 1) = green*0.5; // Green channel
            image_t(i, j, 2) = blue*0.8;// blue channel
        }
    }
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_slytherin_clicked()
{
    image_prev = image_t;
    for (int i = 0; i < image_t.width; ++i) {
        for (int j = 0; j < image_t.height; ++j) {
            unsigned int red = image_t(i, j, 0); // Red channel
            unsigned int green = image_t(i, j, 1); // Green channel
            unsigned int blue = image_t(i, j, 2); // Blue channel
            image_t(i, j, 0) = red*0.6;  // red channel
            image_t(i, j, 1) = green*0.5; // Green channel
            image_t(i, j, 2) = blue*0.8;// blue channel
        }
    }

    for (int i = 0; i < image_t.width; ++i) {
        for (int j = 0; j < image_t.height; ++j) {
            unsigned int red = image_t(i, j, 0); // Red channel
            unsigned int green = image_t(i, j, 1); // Green channel
            unsigned int blue = image_t(i, j, 2); // Blue channel
            image_t(i, j, 0) = red*0.9;  // red channel
            image_t(i, j, 1) = green*0.9; // Green channel
            image_t(i, j, 2) = blue*0.7;// blue channel
        }
    }

    for (int i = 0; i < image_t.width; ++i) {
        for (int j = 0; j < image_t.height; ++j) {
            // Extract RGB components
            unsigned int red = image_t(i, j, 0); // Red channel
            unsigned int green = image_t(i, j, 1); // Green channel
            unsigned int blue = image_t(i, j, 2); // Blue channel

            // Calculate brightness (average of RGB values)
            unsigned int avg = (red + green + blue) / 3;

            // Calculate the proportion of red based on brightness
            unsigned int redProportion = 255 - avg;

            // Set pixel values based on brightness
            image_t(i, j, 0) = 200; // Red channel
            image_t(i, j, 1) = redProportion ; // Green channel
            image_t(i, j, 2) = redProportion; // Blue channel
        }
    }

    for (int i = 0; i < image_t.width; ++i) {           //Width
        for (int j = 0; j < image_t.height; ++j) {       //Height
            for (int k = 0; k < 3; ++k) {   //Channels
                image_t(i, j, k) = 255 - image_t(i, j, k);
            }
        }
    }

    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_previous_clicked()
{
    image_t = image_prev;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_clear_clicked()
{
    image_t = image_i;
    image_prev = image_t;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    imageLabel->clear();
}



void BabyPhotoshop::on_resize_clicked()
{
    image_prev = image_t;
    int newWidth = QInputDialog::getInt(this, "Resize", "Enter the new width", image_t.width, 1, image_t.width);
    int newHeight = QInputDialog::getInt(this, "Resize", "Enter the new height", image_t.height, 1, image_t.height);
    Image resizedImage (newWidth, newHeight);
    double x,y;
    // Calculate scaling factors
    x = image_t.width / newWidth;
    y = image_t.height / newHeight;

    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            for (int k = 0; k < 3; ++k) {
                resizedImage(i, j, k) = round(image_t(x * i, y * j, k));
            }
        }
    }
    image_t = resizedImage;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}

void BabyPhotoshop::on_crop_clicked()
{
    image_prev = image_t;
    int x_cord = QInputDialog::getInt(this, "X coordinate", "Enter the x cordinate of starting point", 0, 0, image_t.width);
    int y_cord = QInputDialog::getInt(this, "Y coordinate", "Enter the y cordinate of starting point", 0, 0, image_t.height);

    int crop_w = QInputDialog::getInt(this, "Crop Width", "Crop width", 0, 0, image_t.width);
    int crop_h = QInputDialog::getInt(this, "Crop Height", "Crop height", 0, 0, image_t.height);

    Image croppedImage(crop_w, crop_h);

    // Copy pixels from the original image to the cropped image
    for (int i = x_cord; i < x_cord + crop_w; ++i) {
        for (int j = y_cord; j < y_cord + crop_h; ++j) {
            for (int k = 0; k < 3; ++k) {
                croppedImage(i - x_cord, j - y_cord, k) = image_t(i, j, k);
            }
        }
    }
    image_t = croppedImage;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}

void BabyPhotoshop::on_detect_clicked()
{
    image_prev = image_t;
    for (int i = 0 ; i < image_t.width ; ++i){
        for (int j = 0 ; j < image_t.height ; ++j){

            unsigned int avg = 0;  // Initializing average value.
            for (int k = 0 ; k < image_t.channels ; ++k){
                avg += image_t (i,j,k);
            }
            avg /= 3;  // Calculating the average.

            for (int k = 0 ; k < image_t.channels ; ++k){
                image_t(i,j,k) = avg ;  // setting the three intensities (RGB channels) to average value.
            }
        }
    }
    Image edge(image_t.width, image_t.height);
    for (int i = 1; i < image_t.width - 1; ++i) {
        for (int j = 1; j < image_t.height - 1; ++j) {
            double hor_gradient;
            double ver_gradient;
            for(int k = 0; k < 3; ++k) {
                int topleft = image_t(i - 1, j - 1, k);
                int left = image_t(i - 1, j, k);
                int bottomleft = image_t(i - 1, j + 1, k);

                int above = image_t(i, j - 1, k);
                int below = image_t(i, j + 1, k);

                int topright = image_t(i + 1, j - 1, k);
                int right = image_t(i + 1, j, k);
                int bottomright = image_t(i + 1, j + 1, k);

                hor_gradient = -topleft + topright - (2 * left) + (2 * right) - bottomleft + bottomright;
                ver_gradient = topleft + (2 * above) + topright - bottomleft - (2 * below) - bottomright;

                double gradient_magnitude = sqrt(pow(hor_gradient, 2) + pow(ver_gradient, 2));

                int threshold = 100; // Adjust this threshold as needed
                if (gradient_magnitude > threshold) {
                    // Set the pixel to black
                    edge(i, j, k) = 0;
                } else {
                    // Set the pixel to white
                    edge(i, j, k) = 255;
                }
            }
        }
    }
    image_t = edge;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_skew_clicked()
{
    image_prev = image_t;
    double angle = 0;
    while (1) {
        angle = QInputDialog::getDouble(this, "Skew angle", "Enter the skew angle", 1, 1, 179);
        if (angle == 90.0) {
            QMessageBox::warning(this, "Invalid Angle", "The angle can't be 90");
        } else {
            break;
        }
    }

    double shift = image_t.height * ( 1.0 / tan(M_PI * angle / 180) );
    Image skewedImage(image_t.width + shift, image_t.height);
    // Loop through each pixel in the image
    for (int i = 0; i < image_t.width; ++i) {
        for (int j = 0; j < image_t.height; ++j) {
            // Copy pixel value from original image to filtered image
            skewedImage( i - j * ( 1.0 / tan(M_PI * angle / 180) ) + shift, j , 0) = image_t(i, j, 0);
            skewedImage(i - j * ( 1.0 / tan(M_PI * angle / 180) )  + shift, j , 1) = image_t(i, j, 1);
            skewedImage(i - j * ( 1.0 / tan(M_PI * angle / 180) )  + shift, j , 2) = image_t(i, j, 2);
        }
    }
    // Update the original image with the filtered image
    image_t = skewedImage;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }

}


void BabyPhotoshop::on_oil_clicked()
{
    image_prev = image_t;
    int radius = 2;
    int intensity = 3;
    int w = image_t.width;
    int h = image_t.height;

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            std::vector<int> intensity_count(256, 0);
            std::vector<int> avg_red(256, 0);
            std::vector<int> avg_green(256, 0);
            std::vector<int> avg_blue(256, 0);
            // Looping over neighboring pixels
            for (int x = i - radius; x < i + radius + 1; ++x) {
                for (int y = j - radius; y < j + radius + 1; ++y) {
                    if (x >= 0 && x < w) {
                        if (y >= 0 && y < h) {
                            int Red = image_t(x, y, 0);
                            int Green = image_t(x, y, 1);
                            int Blue = image_t(x, y, 2);

                            int intensitylevel = ((Red + Green + Blue) / 3 * intensity) / 255;

                            intensity_count[intensitylevel]++;
                            avg_red[intensitylevel] += Red;
                            avg_green[intensitylevel] += Green;
                            avg_blue[intensitylevel] += Blue;
                        }
                    }
                }
            }

            int _max = 0;
            for (int c = 1; c < 256; ++c) {
                if (intensity_count[c] > intensity_count[_max]) {
                    _max = c;
                }
            }

            if (intensity_count[_max] != 0) {
                image_t(i, j, 0) = avg_red[_max] / intensity_count[_max];
                image_t(i, j, 1) = avg_green[_max] / intensity_count[_max];
                image_t(i, j, 2) = avg_blue[_max] / intensity_count[_max];
            }
        }
    }

    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}


void BabyPhotoshop::on_merge_clicked()
{
    QString file2 = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.tga *.jpeg *.bmp)");
    Image img2(file2.toStdString());
    image_prev = image_t;
    int w = image_t.width;
    int h = image_t.height;
    Image resizedImage(w, h);
    double x,y;
    // Calculate scaling factors
    x = img2.width / w;
    y = img2.height / h;
    //Resizing
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < 3; ++k) {
                resizedImage(i, j, k) = round(img2(x * i, y * j, k));
            }
        }
    }
    img2 = resizedImage;
    Image merged(w, h);
    //Merging
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            int R, G, B;
            R = (image_t(i, j, 0) + img2(i, j, 0)) / 2;
            G = (image_t(i, j, 1) + img2(i, j, 1)) / 2;
            B = (image_t(i, j, 2) + img2(i, j, 2)) / 2;
            merged(i, j, 0) = R;
            merged(i, j, 1) = G;
            merged(i, j, 2) = B;
        }
    }
    image_t = merged;
    image_t.saveImage("temp.jpg");
    QLabel* imageLabel = findChild<QLabel*>("image2");
    if (imageLabel) {
        // Load image
        QPixmap image(Qtemp);

        // Get label's width
        int labelWidth = imageLabel->width();

        // Rescale image to fit label width while maintaining aspect ratio
        QPixmap scaledImage = image.scaledToWidth(labelWidth, Qt::FastTransformation);

        // Set the scaled image on the label
        imageLabel->setPixmap(scaledImage);
    }
}

