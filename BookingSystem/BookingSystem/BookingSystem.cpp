#include "../PresentationLayer/PresentationLayer.hpp"

int main()
{
    PresentationLayer presentationLayer;
    presentationLayer.createWindow();
    presentationLayer.data->select("Deni", "Osussogurnost");
    presentationLayer.closeWindow();
}