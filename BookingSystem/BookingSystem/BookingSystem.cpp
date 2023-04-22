#include "../LogicLayer/LogicLayer.hpp"
#include "../DataLayer/DataLayer.hpp"
#include "../PresentationLayer/PresentationLayer.hpp"

int main()
{
    PresentationLayer presentationLayer;
    DataLayer dataLayer;
    dataLayer.connect();

    presentationLayer.createWindow();
    presentationLayer.closeWindow();
}