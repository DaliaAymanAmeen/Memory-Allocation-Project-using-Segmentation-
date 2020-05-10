#include "functions.h"

#include<QString>
#include<QVector>
#include<QDebug>
//Functions::Functions()
//{

//}


void add_holes(QVector<segment>&v, QVector<int> adress, QVector<int> size, int total) {
    /*function that takes two QVectors to put the holes in the memory QVector
    one contatins the starting addresses of each hole
    the second contating the size of each hole
    the memory QVector is the first parameter
    it has to update the memory QVector with the holes
    and add data segments to the places already taken*/
    int temp;
    int holes_no = (adress.size());
    //sorting holes according to the adress
    for (int i = 0; i<holes_no; i++) {
        for (int j = i + 1; j<holes_no; j++) {
            if (adress[j]<adress[i]) {
                temp = adress[i];
                adress[i] = adress[j];
                adress[j] = temp;
                temp = size[i];
                size[i] = size[j];
                size[j] = temp;
            }
        }
    }
    //check if the start is data
    if (adress[0] != 0)
    {

        v.push_back(segment("segment0", "parent0", 0, adress[0]));
        v.push_back(segment(adress[0], size[0]));
        for (int i = 1; i<holes_no; i++) {
            v.push_back(segment("segment0", "parent0", adress[i - 1] + size[i - 1], adress[i] - adress[i - 1] - size[i - 1]));
            v.push_back(segment(adress[i], size[i]));


        }
        //add data at the end if last hole doesn't end at the end of the memory
        if ((adress[holes_no - 1] + size[holes_no - 1])<total) {

            v.push_back(segment("segment0", "parent0", adress[holes_no - 1] + size[holes_no - 1], total - adress[holes_no - 1] - size[holes_no - 1]));

        }

    }
    //check if the start is hole
    else {

        v.push_back(segment(adress[0], size[0]));
        for (int i = 1; i<holes_no; i++) {
            v.push_back(segment("segment0", "parent0", adress[i - 1] + size[i - 1], adress[i] - adress[i - 1] - size[i - 1]));
            v.push_back(segment(adress[i], size[i]));
        }
        //add data at the end if last hole doesn't end at the end of the memory
        if ((adress[holes_no - 1] + size[holes_no - 1])<total) {

            v.push_back(segment("segment0", "parent0", adress[holes_no - 1] + size[holes_no - 1], total - adress[holes_no - 1] - size[holes_no - 1]));

        }

    }

}

int bestIndex;
bool best_fit_alloc(QVector<segment>&memory, QVector<QString>names, QVector<int>size, QString parent) {
    QVector<segment> check = memory;
    bool place_is_found = true;
    for (int i = 0; i<names.size(); i++)
    {
        int bestIndex = -1;
        for (int j = 0; j <check.size(); j++)
        {
            if (check[j].hole == true)
            {
                if (check[j].size >= size[i])
                {

                    if (bestIndex == -1)
                    {bestIndex = j;}

                    else if (check[bestIndex].size > check[j].size)
                        bestIndex = j;
                    qDebug() << bestIndex;
                }
            }
        }
        if (bestIndex == -1) {
            place_is_found = false;
            return false;
            break;
        }
        if (check[bestIndex].size == size[i]) {
            check[bestIndex].name = names[i];
            check[bestIndex].hole = false;
            check[bestIndex].parent = parent;
            place_is_found = true;
        }
        else if (check[bestIndex].size > size[i])
        {
            int it = bestIndex + 1;
            check[bestIndex].size -= size[i];

            check.insert(check.begin() + it,segment (names[i], parent, (check[bestIndex].address + check[bestIndex].size), size[i]));

            place_is_found = true;
        }
    }


    if (place_is_found == true) {
        memory = check;
    }
    return true;
}


bool first_fit_alloc(QVector<segment>&memory, QVector<QString>names, QVector<int>size, QString parent) {
    QVector<segment> check_1 = memory;
    bool place_is_found_1 = false;
    for (int i = 0; i <names.size(); i++)
    {
        for (int j = 0; j <check_1.size(); j++)
        {
            if (check_1[j].hole == true)
            {
                if (check_1[j].size == size[i]) {
                    check_1[j].name = names[i];
                    check_1[j].hole = false;
                    check_1[j].parent = parent;
                    place_is_found_1 = true;
                    break;

                }
                else if (check_1[j].size > size[i]) {
                    int it_1 = j + 1;
                    check_1[j].size -= size[i];
                    place_is_found_1 = true;
                    check_1.insert(check_1.begin() + it_1,segment (names[i], parent, (check_1[j].address + check_1[j].size), size[i]) );

                    break;
                }

            }
        }
        if (place_is_found_1 == false) {
            return false;
        }
    }


        memory = check_1;
        return true;

}


QVector<segment> seg_table(QVector<segment>&v, QString proc) {

    /*function that takes a process name then find all the segments for that process and add them to a vector of segments and return that vector
    the memory vector is the first parameter*/

    QVector<segment> seg;

    copy_if(v.begin(), v.end(), std::back_inserter(seg), [proc]( const segment &s)
    {
            return s.parent == proc;

    });


    return seg;

}

void de_alloc(QVector<segment>&v, QString proc) {
    /*function that takes a process name then find all the segments for that process and remove them from the memory
    then check if there is a hole before or after it then it should increase the hole size
    if not then it add a new hole to the memory vector
    the memory vector is the first parameter*/
    for (int i = 0; i < v.size(); i++) {
        if (v[i].hole)
            continue;
        if (v[i].parent == proc) {
            if(i==0){
                if (v[i + 1].hole) {
                    v[i + 1].size += v[i].size;
                    v[i + 1].address = v[i].address;
                    v.erase(v.begin() + i);
                    i--;
                    continue;
                }
                else {
                    v[i].hole = true;
                    v[i].parent = "";
                    v[i].name = "";
                    continue;
                }
            }
            if (i+1 >= v.size()) {
                if (v[i - 1].hole) {
                    v[i - 1].size += v[i].size;
                    v.erase(v.begin() + i);
                    i--;
                    continue;
                }
                else {
                    v[i].hole = true;
                    v[i].parent = "";
                    v[i].name = "";
                    continue;
                }
            }


            if (v[i - 1].hole) {
                v[i - 1].size += v[i].size;
                v.erase(v.begin() + i);
                i--;
            }
            else if (v[i + 1].hole) {
                v[i + 1].size += v[i].size;
                v[i + 1].address = v[i].address;
                v.erase(v.begin() + i);
                i--;
            }
            else {
                v[i].hole = true;
                v[i].parent = "";
                v[i].name = "";
            }


        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (!v[i].hole)
            continue;
        if (v[i].hole) {
            if (i + 1 < v.size()) {
                if (v[i + 1].hole) {
                    v[i].size += v[i + 1].size;
                    v.erase(v.begin() + i + 1);
                    i--;
                }
            }
        }
    }
}






