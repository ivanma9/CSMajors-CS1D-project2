#include "mapds.h"

mapDS::mapDS()
{
    dataSize = 0;
    NULL_SOUVENIR_LIST << Souvenir("NULL", -1.0);
}

mapDS::mapDS(int size)
{
    data.reserve(size);
    dataSize = size;
    NULL_SOUVENIR_LIST << Souvenir("NULL", -1.0);

}

mapDS::~mapDS(){}

int mapDS::getDataSize() const
{
    return dataSize;
}

void mapDS::insert(QString key, QString item, double price)
{
    int index = searchStadium(key);

    if(index == -1)
    {   //insert new element
        data.push_back(key);

        data[dataSize].addSouvenir(item,price);

        dataSize++;
    }
    else
    {   //insert souvenir element
        data[index].addSouvenir(item,price);
    }
}

void mapDS::remove(QString key)
{
    int index = searchStadium(key);

    if(index != -1)
    data.removeAt(index);
}

void mapDS::changePrice(const QString key, const QString item, double price)
{
    int keyIndex = searchStadium(key);
    int souvIndex = searchSouvenir(keyIndex,item);

    if(keyIndex != -1)
    data[keyIndex].data[souvIndex].price = price;
}

void mapDS::removeSouv(QString key, QString item)
{
    int keyIndex = searchStadium(key);
    int souvIndex = searchSouvenir(keyIndex,item);

    if(keyIndex != -1)
        data[keyIndex].data.removeAt(souvIndex);
}

int mapDS::searchStadium(QString key)
{
    int index = -1;
    for(int i = 0; i < dataSize; i++)
    {
        if(key == data[i].key)
        {
            index = i;
            i = dataSize; // ends teh loop
        }
    }

    return index;
}

int mapDS::searchSouvenir(int key, QString item)
{
    int index = -1;
    for(int i = 0; i < dataSize; i++)
    {
        if(item == data[key].data[i].name)
        {
            index = i;
            i = dataSize; // ends teh loop
        }
    }

    return index;
}

int mapDS::searchSouvenir(QString key, QString item)
{
    int index = searchStadium(key);

    return searchSouvenir(index, item);
}


QList<Souvenir> mapDS::getSouvenir(QString key)
{
    int index = searchStadium(key);
    if(index == -1)
        return NULL_SOUVENIR_LIST;
    else
        return data[index].data;

}
