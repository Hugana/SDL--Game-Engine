#ifndef TILEMAP_H
#define TILEMAP_H


class tileMap
{
    public:
        tileMap();
        virtual ~tileMap();
        void loadMap();
        void drawMap();

    protected:

    private:
        int map[20][20];
};

#endif // TILEMAP_H
