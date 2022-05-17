//
// Created by zxx on 2022/5/17.
//

#ifndef WORKSPACEC_DATASTORE_H
#define WORKSPACEC_DATASTORE_H

struct Student{
    int id;
    char name[16];
    Student *next;
};

class DataStore {
public:
    DataStore();

    ~DataStore();

public:
    void Add(const Student *data);

    Student *Find(int id);

    void Print();

private:
    Student m_head;

};


#endif //WORKSPACEC_DATASTORE_H
