#ifndef MAPDS_H
#define MAPDS_H

#include <QList>
#include <QString>

struct Souvenir
{
    QString name;
    double price;

    Souvenir(QString newName, double newPrice)
    : name(newName), price(newPrice){}
};

struct MapStructure
{
    QString key; // Stadium name

    QList<Souvenir> data; // Souvenir

    MapStructure(QString newKey) : key(newKey){}

    void addSouvenir(QString newName, double newPrice)
    {
       data.push_back(Souvenir(newName, newPrice));
    }


};

class mapDS // MAP key value = Stadium, data = souvenirs
{
private:
    QList<MapStructure> data;
    int dataSize;

public:
    mapDS();
    mapDS(int size);
    ~mapDS();

    int getDataSize() const;

    //put a new element in the data or just adds a new souvenir
    void insert(QString key, QString item, double price);
    //remove a data
    void remove(QString key);
    //remove a souvenir
    void removeSouv(QString key, QString item);

    //given the key(Stadium), item name and price, changes the price
    void changePrice(const QString key, const QString item, double price);

    //returns index of the key
    int searchStadium(QString key);

    //returns index of the data
    int searchSouvenir(int key, QString item);
    int searchSouvenir(QString key, QString item); // when the key's index has not been found

    //returns the data(Souvenir) of the key(Stadium)
    QList<Souvenir> getSouvenir(QString key);

    //return if getSouvenir couldn't find the key
    QList<Souvenir> NULL_SOUVENIR_LIST;

};

#endif // MAPDS_H
