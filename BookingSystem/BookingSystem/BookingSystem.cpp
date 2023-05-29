#include "../PresentationLayer/PresentationLayer.hpp"

int main()
{
    PresentationLayer presentationLayer;
    presentationLayer.data->select("vatev", "NaiSilnataParola");
    presentationLayer.createWindow();
    presentationLayer.closeWindow();
}