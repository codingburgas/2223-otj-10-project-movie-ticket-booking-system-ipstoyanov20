#include "../LogicLayer/LogicLayer.hpp"
#include "../DataLayer/DataLayer.hpp"
#include "../PresentationLayer/PresentationLayer.hpp"

int main()
{
    PresentationLayer presentationLayer;
    Data data;
    data.select(2);
    presentationLayer.createWindow();

    presentationLayer.closeWindow();
}