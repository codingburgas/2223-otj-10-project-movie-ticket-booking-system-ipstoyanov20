#include "../LogicLayer/LogicLayer.hpp"
#include "../DataLayer/DataLayer.hpp"
#include "../PresentationLayer/PresentationLayer.hpp"

int main()
{
    PresentationLayer presentationLayer;
    Data* data = Data::getInstance();
    data->select(1);
    presentationLayer.createWindow();

    presentationLayer.closeWindow();
}