/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestApplication.cpp
 * Author: giovani
 * 
 * Created on 31 de Outubro de 2016, 21:22
 */

#include "TestApplication.h"
#include "Traits.h"
#include <cstring>

/*
 .data
FIRST_ARRAY_ELEMENT: .word 24

.text
la $s0, FIRST_ARRAY_ELEMENT #ponteiro para o 1º elemento do array
add $s1, $s1, $zero 
loop:
add $t0, $s0, $s1
sll $t0, $t0, 2
lw $t1, 0($t0)
addi $t2, $t2, 64 #bytes, a cada 16 posições do array, modifica essa posição
divi $t1, $s1, $t2

bnez $HI, read #o registrador $HI guarda o resto da divisão
addi $t4, $t4, 108 #se a posição for divisor de 16, coloca 108 na posição do array
sw $t4 0($t0)
read:
addi $t3, $t3, 224 #bytes, array de 56 posições
slt $t5, $t0, $t3
beq $t5, $zero, loop
 */
TestApplication::TestApplication() {
    createAddressSpace();
    generateMemoryReferences();
}

TestApplication::TestApplication(const TestApplication& orig) {
    addressSpaceChunks = orig.addressSpaceChunks;
    memoryReferences = orig.memoryReferences;
}

TestApplication::~TestApplication() {
}

void TestApplication::createAddressSpace() {
    DataMemoryChunk chunk0 = DataMemoryChunk(0, true, true, true);
    fillStartupApplicationSection(chunk0);
    addressSpaceChunks.push_back(chunk0);

    DataMemoryChunk chunk1 = DataMemoryChunk(1 * PAGESIZE_IN_WORDS, true, true, false);
    fillChunkData(chunk1, 1);
    addressSpaceChunks.push_back(chunk1);

    DataMemoryChunk chunk2 = DataMemoryChunk(2 * PAGESIZE_IN_WORDS, true, true, false);
    fillChunkData(chunk2, 2);
    addressSpaceChunks.push_back(chunk2);

    DataMemoryChunk chunk3 = DataMemoryChunk(3 * PAGESIZE_IN_WORDS, false, true, false);
    fillChunkData(chunk3, 32);
    addressSpaceChunks.push_back(chunk3);

    DataMemoryChunk chunk4 = DataMemoryChunk(4 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk4, 4);
    addressSpaceChunks.push_back(chunk4);

    DataMemoryChunk chunk5 = DataMemoryChunk(5 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk5, 8);
    addressSpaceChunks.push_back(chunk5);

    DataMemoryChunk chunk6 = DataMemoryChunk(6 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk6, 15);
    addressSpaceChunks.push_back(chunk6);

    DataMemoryChunk chunk7 = DataMemoryChunk(7 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk7, 16);
    addressSpaceChunks.push_back(chunk7);

    DataMemoryChunk chunk8 = DataMemoryChunk(8 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk8, 23);
    addressSpaceChunks.push_back(chunk8);

    DataMemoryChunk chunk9 = DataMemoryChunk(9 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk9, 42);
    addressSpaceChunks.push_back(chunk9);

    DataMemoryChunk chunk10 = DataMemoryChunk(10 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk10, 11);
    addressSpaceChunks.push_back(chunk10);

    DataMemoryChunk chunk11 = DataMemoryChunk(11 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk11, 9);
    addressSpaceChunks.push_back(chunk11);

    DataMemoryChunk chunk12 = DataMemoryChunk(12 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk12, 17);
    addressSpaceChunks.push_back(chunk12);

    DataMemoryChunk chunk13 = DataMemoryChunk(13 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk13, 5);
    addressSpaceChunks.push_back(chunk13);

    DataMemoryChunk chunk14 = DataMemoryChunk(14 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk14, 29);
    addressSpaceChunks.push_back(chunk14);

    DataMemoryChunk chunk15 = DataMemoryChunk(15 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk15, 22);
    addressSpaceChunks.push_back(chunk15);
}

void TestApplication::fillStartupApplicationSection(DataMemoryChunk& chunk) {
    Information info[PAGESIZE_IN_WORDS];
    memset(info, 0, sizeof (Information) * PAGESIZE_IN_WORDS);
    info[0] = 536879104;
    info[1] = 12;
    info[2] = 545267713;
    info[3] = 134217729;
    chunk.setData(info);
}

void TestApplication::fillChunkData(DataMemoryChunk& chunk, int value) {
    Information info[PAGESIZE_IN_WORDS];
    std::fill(info, info + PAGESIZE_IN_WORDS, value);
    chunk.setData(info);
}

void TestApplication::generateMemoryReferences() {    
    memoryReferences.push_back(MemoryAccess(0, Operation::Read));
    memoryReferences.push_back(MemoryAccess(16, Operation::Read)); // la $s0, FIRST_ARRAY_ELEMENT
    memoryReferences.push_back(MemoryAccess(1, Operation::Read)); // add $s1, $s1, $zero

    int addressSpaceSize = Traits<Process>::maxAddressSpace / sizeof (Information);
    int arraySize = addressSpaceSize - INITIAL_ARRAY_ADDRESS - PAGESIZE_IN_WORDS;

    for (int i = INITIAL_ARRAY_ADDRESS; i < arraySize + INITIAL_ARRAY_ADDRESS; i++) {
        memoryReferences.push_back(MemoryAccess(2, Operation::Read)); // add $t0, $s0, $s1
        memoryReferences.push_back(MemoryAccess(3, Operation::Read)); // sll $t0, $t0, 2
        memoryReferences.push_back(MemoryAccess(4, Operation::Read));
        memoryReferences.push_back(MemoryAccess(i, Operation::Read)); // lw $t1, 0($t0)
        memoryReferences.push_back(MemoryAccess(5, Operation::Read)); // addi $t2, $t2, 64
        memoryReferences.push_back(MemoryAccess(6, Operation::Read)); // divi $t1, $s1, $t2
        memoryReferences.push_back(MemoryAccess(7, Operation::Read)); // bnez $HI, read
        if ((i - INITIAL_ARRAY_ADDRESS) % 16 == 0) {
            memoryReferences.push_back(MemoryAccess(8, Operation::Read)); // addi $t4, $t4, 108
            memoryReferences.push_back(MemoryAccess(9, Operation::Read));
            memoryReferences.push_back(MemoryAccess(i, Operation::Write, 108)); // sw $t4 0($t0)
        }
        memoryReferences.push_back(MemoryAccess(10, Operation::Read)); // read: addi $t3, $t3, 416
        memoryReferences.push_back(MemoryAccess(11, Operation::Read)); // slt $t5, $t0, $t3
        memoryReferences.push_back(MemoryAccess(12, Operation::Read)); // beq $t5, $zero, loop
    }
}
