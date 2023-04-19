#include "../LogicLayer/LogicLayer.hpp"
#include "../DataLayer/DataLayer.hpp"
#include "../PresentationLayer/PresentationLayer.hpp"

int main()
{
    PresentationLayer presentationLayer;
    presentationLayer.createWindow();
    presentationLayer.closeWindow();
}