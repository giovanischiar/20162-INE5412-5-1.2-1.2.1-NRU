/*
 * File:   System.cpp
 * Author: cancian
 *
 * Created on October 9, 2015, 9:04 PM
 */
#include <string>
#include <cstring>

#include "OperatingSystem.h"
#include "Application.h"
#include "HW_CPU.h"
#include "HW_Machine.h"
#include "Simulator.h"
#include "DataMemoryChunk.h"

void OperatingSystem::LoadApplication(Application* app, MMU::PhysicalAddress address) {
    Debug::cout(Debug::Level::trace, "OperatingSystem::LoadApplication(" + std::to_string(reinterpret_cast<unsigned long> (app)) + "," + std::to_string(address) + ")");
    std::list<Application::Information> code = app->getCode();
    HW_MMU::Information info;
    for (std::list<HW_MMU::Information>::iterator it = code.begin(); it != code.end(); it++) {
        info = (*it);
        HW_Machine::RAM()->write(address, info);
        address++;
    }
}

void OperatingSystem::SetBootApplication(Application* app) {
    Debug::cout(Debug::Level::trace, "OperatingSystem::SetBootApplication(" + std::to_string(reinterpret_cast<unsigned long> (app)) + ")");
    HW_CPU::Register address = HW_Machine::CPU()->readRegister(HW_CPU::pc);
    LoadApplication(app, address);
}

void OperatingSystem::Init() {
    Debug::cout(Debug::Level::trace, "OperatingSystem::init()");
    HW_Machine::Init();

    OperatingSystem::CPU_Mediator();
    OperatingSystem::DMA_Mediator();
    OperatingSystem::HardDisk_Mediator();
    OperatingSystem::MMU_Mediator();
    OperatingSystem::Timer_Mediator();

    SetBootApplication(Application::DefaultBootApplication()); // load boot application into RAMs

    //Test Setup
    OperatingSystem::createSwap();
}

void OperatingSystem::ExecuteTestCode() {
    Debug::cout(Debug::Level::trace, "OperatingSystem::ExecuteTestCode()");
    Simulator* simulator = Simulator::getInstance();
    Entity* entity = simulator->getEntity();
    Module* module = simulator->getModule();
    int executionStep = std::stoi(entity->getAttribute("ExecutionStep")->getValue());
    double timeNow = simulator->getTnow();

    // INSERT HERE YOUR CODE
    // You can write a test code that will be executed and will invoke system calls or whenever you want
    // Follow the examples...
    // ...

    switch (executionStep) {
        case 0: // ExecutionStep is initialized with 0
            Debug::cout(Debug::Level::trace, "ExecutionStep: " + std::to_string(0));
            entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step
            HW_Machine::RAM()->dump();
            HW_Machine::MMU()->readMemory(PAGESIZE_IN_WORDS);







            break;
        case 1:
            Debug::cout(Debug::Level::trace, "ExecutionStep: " + std::to_string(1));
            entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step




            break;
        case 2:
            Debug::cout(Debug::Level::trace, "ExecutionStep: " + std::to_string(2));
            entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step



            break;
        case 3:
            Debug::cout(Debug::Level::trace, "ExecutionStep: " + std::to_string(3));
            entity->getAttribute("ExecutionStep")->setValue(std::to_string(++executionStep)); // advance execution step




            break;
        case 4:
            Debug::cout(Debug::Level::trace, "ExecutionStep: " + std::to_string(4));
            entity->getAttribute("ExecutionStep")->setValue(std::to_string(0)); // advance execution step



            break;
    }
}

void OperatingSystem::createSwap() {
    std::vector<DataMemoryChunk> chunks;
    DataMemoryChunk chunk0 = DataMemoryChunk(0, true, true, true);
    fillOS(chunk0);
    chunks.push_back(chunk0);

    DataMemoryChunk chunk1 = DataMemoryChunk(1 * PAGESIZE_IN_WORDS, true, true, false);
    fillChunkData(chunk1, 4);
    chunks.push_back(chunk1);

    DataMemoryChunk chunk2 = DataMemoryChunk(2 * PAGESIZE_IN_WORDS, true, true, false);
    fillChunkData(chunk2, 8);
    chunks.push_back(chunk2);

    DataMemoryChunk chunk3 = DataMemoryChunk(3 * PAGESIZE_IN_WORDS, true, true, false);
    fillChunkData(chunk3, 15);
    chunks.push_back(chunk3);

    DataMemoryChunk chunk4 = DataMemoryChunk(4 * PAGESIZE_IN_WORDS, true, true, false);
    fillChunkData(chunk4, 16);
    chunks.push_back(chunk4);

    DataMemoryChunk chunk5 = DataMemoryChunk(5 * PAGESIZE_IN_WORDS, false, true, false);
    fillChunkData(chunk5, 23);
    chunks.push_back(chunk5);

    DataMemoryChunk chunk6 = DataMemoryChunk(6 * PAGESIZE_IN_WORDS, false, true, false);
    fillChunkData(chunk6, 42);
    chunks.push_back(chunk6);

    DataMemoryChunk chunk7 = DataMemoryChunk(7 * PAGESIZE_IN_WORDS, false, true, false);
    fillChunkData(chunk7, 108);
    chunks.push_back(chunk7);

    DataMemoryChunk chunk8 = DataMemoryChunk(8 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk8, 11);
    chunks.push_back(chunk8);

    DataMemoryChunk chunk9 = DataMemoryChunk(9 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk9, 9);
    chunks.push_back(chunk9);

    DataMemoryChunk chunk10 = DataMemoryChunk(10 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk10, 17);
    chunks.push_back(chunk10);

    DataMemoryChunk chunk11 = DataMemoryChunk(11 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk11, 5);
    chunks.push_back(chunk11);

    DataMemoryChunk chunk12 = DataMemoryChunk(12 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk12, 2);
    chunks.push_back(chunk12);

    DataMemoryChunk chunk13 = DataMemoryChunk(13 * PAGESIZE_IN_WORDS, false, true, true);
    fillChunkData(chunk13, 0);
    chunks.push_back(chunk13);

    OperatingSystem::Memory_Manager()->fillSwap(chunks);
}

void OperatingSystem::fillOS(DataMemoryChunk& chunk) {
    Information info[PAGESIZE_IN_WORDS];
    memset(info, 0, sizeof (Information) * PAGESIZE_IN_WORDS);
    info[0] = 536879104;
    info[1] = 12;
    info[2] = 545267713;
    info[3] = 134217729;
    chunk.setData(info);
}

void OperatingSystem::fillChunkData(DataMemoryChunk& chunk, int value) {
    Information info[PAGESIZE_IN_WORDS];
    std::fill(info, info + PAGESIZE_IN_WORDS, value);
    chunk.setData(info);
}

/*
 Not used
 */
HW_MMU::Information OperatingSystem::asmm(std::string mnemonic) {
    HW_MMU::Information bincode;
    /* @TODO 
     */
    if (mnemonic == "Process:exec()") {
        bincode = 0xFFFFFFFF; // - (HW_CPU::addi<<24) + 
    }
    //@TODO
    bincode = (HW_CPU::addi << 26) + (HW_CPU::s0 << 21) + (HW_CPU::s1 << 16) + 1; // for tests purpose only
    return bincode;
}