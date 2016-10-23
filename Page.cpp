/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Page.cpp
 * Author: giovani
 * 
 * Created on 23 de Outubro de 2016, 02:43
 */

#include "Page.h"

Page::Page(Information (& data)[PAGESIZE], bool isReadable, bool isWritable, bool isExecutable)
    :   isReadable(isReadable),
        isWritable(isWritable),
        isExecutable(isExecutable)
{
    std::copy(std::begin(data), std::end(data), std::begin(this->data));
}

Page::Page(const Page& orig) {
}

Page::~Page() {
}

bool Page::isIsExecutable() const {
    return isExecutable;
}

bool Page::isIsWritable() const {
    return isWritable;
}

bool Page::isIsReadable() const {
    return isReadable;
}

Information const* Page::getData() const{return data;}

