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
#include <iostream>

Page::Page(LogicalAddress base, Information (& data)[PAGESIZE_IN_WORDS], bool isReadable, bool isWritable, bool isExecutable)
    :   base(base),    
        isReadable(isReadable),
        isWritable(isWritable),
        isExecutable(isExecutable)
{
    std::copy(std::begin(data), std::end(data), std::begin(this->data));
}

Page::Page(const Page& orig) {
    this->base = orig.getBase();
    std::copy(orig.getData(), orig.getData()+PAGESIZE_IN_WORDS, this->data);
    this->isExecutable = orig.isIsExecutable();
    this->isReadable = orig.isIsReadable();
    this->isWritable = orig.isIsWritable();
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

Information const * Page::getData() const {
    return data;
}

Information Page::getValue(unsigned int wordIndex) const {   
    std::cout << "get Page.data[" << wordIndex-base << "] = " << data[wordIndex-base] << std::endl;
    return data[wordIndex-base];
}

LogicalAddress Page::getBase() const {
    return base;
}
