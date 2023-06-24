#include <stdio.h>
#include <stdlib.h>
#include <tesseract/capi.h>
#include <leptonica/allheaders.h>

int main()
{
    const char* image_path = "path_to_your_image.jpg";

    // Initialize Tesseract OCR engine
    tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize Tesseract.\n");
        exit(1);
    }

    // Load the image using Leptonica library
    Pix* image = pixRead(image_path);
    if (image == NULL) {
        fprintf(stderr, "Could not open image file.\n");
        exit(1);
    }

    // Set the image for OCR
    api->SetImage(image);

    // Perform OCR
    char* text = api->GetUTF8Text();
    printf("Extracted Text:\n%s", text);

    // Clean up
    api->End();
    delete[] text;
    pixDestroy(&image);

    return 0;
}