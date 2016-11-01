#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Abstr_Alarm.o \
	${OBJECTDIR}/Abstr_FileAllocationTable.o \
	${OBJECTDIR}/Abstr_FileAllocator.o \
	${OBJECTDIR}/Abstr_FileSystem.o \
	${OBJECTDIR}/Abstr_MemoryChunk.o \
	${OBJECTDIR}/Abstr_MemoryManager.o \
	${OBJECTDIR}/Abstr_Process.o \
	${OBJECTDIR}/Abstr_Scheduler.o \
	${OBJECTDIR}/Abstr_Thread.o \
	${OBJECTDIR}/Application.o \
	${OBJECTDIR}/DataMemoryChunk.o \
	${OBJECTDIR}/HW_CPU.o \
	${OBJECTDIR}/HW_DMA.o \
	${OBJECTDIR}/HW_HardDisk.o \
	${OBJECTDIR}/HW_MMU.o \
	${OBJECTDIR}/HW_MMU_Continuous.o \
	${OBJECTDIR}/HW_MMU_Paging.o \
	${OBJECTDIR}/HW_MMU_Segmentation.o \
	${OBJECTDIR}/HW_Machine.o \
	${OBJECTDIR}/HW_RAM.o \
	${OBJECTDIR}/HW_Timer.o \
	${OBJECTDIR}/Mediator_CPU.o \
	${OBJECTDIR}/Mediator_DMA.o \
	${OBJECTDIR}/Mediator_HardDisk.o \
	${OBJECTDIR}/Mediator_MMU.o \
	${OBJECTDIR}/Mediator_Timer.o \
	${OBJECTDIR}/Model.o \
	${OBJECTDIR}/ModelBuilder.o \
	${OBJECTDIR}/Module.o \
	${OBJECTDIR}/ModuleCreate.o \
	${OBJECTDIR}/ModuleDispose.o \
	${OBJECTDIR}/ModuleInvoke_HardwareEvent.o \
	${OBJECTDIR}/ModuleInvoke_PulseExecution.o \
	${OBJECTDIR}/NRU.o \
	${OBJECTDIR}/OperatingSystem.o \
	${OBJECTDIR}/Page.o \
	${OBJECTDIR}/PageTable.o \
	${OBJECTDIR}/ProblemSolving20162ModelBuilder.o \
	${OBJECTDIR}/ProblemTester.o \
	${OBJECTDIR}/Simul_Debug.o \
	${OBJECTDIR}/Simul_Entity.o \
	${OBJECTDIR}/Simul_Event.o \
	${OBJECTDIR}/Simul_Statistics.o \
	${OBJECTDIR}/Simul_Util.o \
	${OBJECTDIR}/Simulator.o \
	${OBJECTDIR}/SourceModule.o \
	${OBJECTDIR}/TestApplication.o \
	${OBJECTDIR}/Util_Queue.o \
	${OBJECTDIR}/Util_Scheduling_Queue.o \
	${OBJECTDIR}/VirtualMemorySwap.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/MemoryManagerTest.o \
	${TESTDIR}/tests/MemoryManagerTestRunner.o \
	${TESTDIR}/tests/NRUTest.o \
	${TESTDIR}/tests/NRUTestRunner.o \
	${TESTDIR}/tests/PageTableTest.o \
	${TESTDIR}/tests/PageTableTestRunner.o \
	${TESTDIR}/tests/VirtualMemorySwapTest.o \
	${TESTDIR}/tests/newtestrunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11 -fpermissive
CXXFLAGS=-std=c++11 -fpermissive

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20162-ine5412-5-1-2-1.2.1-nru

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20162-ine5412-5-1-2-1.2.1-nru: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20162-ine5412-5-1-2-1.2.1-nru ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Abstr_Alarm.o: Abstr_Alarm.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Alarm.o Abstr_Alarm.cpp

${OBJECTDIR}/Abstr_FileAllocationTable.o: Abstr_FileAllocationTable.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileAllocationTable.o Abstr_FileAllocationTable.cpp

${OBJECTDIR}/Abstr_FileAllocator.o: Abstr_FileAllocator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileAllocator.o Abstr_FileAllocator.cpp

${OBJECTDIR}/Abstr_FileSystem.o: Abstr_FileSystem.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileSystem.o Abstr_FileSystem.cpp

${OBJECTDIR}/Abstr_MemoryChunk.o: Abstr_MemoryChunk.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_MemoryChunk.o Abstr_MemoryChunk.cpp

${OBJECTDIR}/Abstr_MemoryManager.o: Abstr_MemoryManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_MemoryManager.o Abstr_MemoryManager.cpp

${OBJECTDIR}/Abstr_Process.o: Abstr_Process.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Process.o Abstr_Process.cpp

${OBJECTDIR}/Abstr_Scheduler.o: Abstr_Scheduler.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Scheduler.o Abstr_Scheduler.cpp

${OBJECTDIR}/Abstr_Thread.o: Abstr_Thread.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Thread.o Abstr_Thread.cpp

${OBJECTDIR}/Application.o: Application.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Application.o Application.cpp

${OBJECTDIR}/DataMemoryChunk.o: DataMemoryChunk.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataMemoryChunk.o DataMemoryChunk.cpp

${OBJECTDIR}/HW_CPU.o: HW_CPU.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_CPU.o HW_CPU.cpp

${OBJECTDIR}/HW_DMA.o: HW_DMA.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_DMA.o HW_DMA.cpp

${OBJECTDIR}/HW_HardDisk.o: HW_HardDisk.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_HardDisk.o HW_HardDisk.cpp

${OBJECTDIR}/HW_MMU.o: HW_MMU.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU.o HW_MMU.cpp

${OBJECTDIR}/HW_MMU_Continuous.o: HW_MMU_Continuous.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Continuous.o HW_MMU_Continuous.cpp

${OBJECTDIR}/HW_MMU_Paging.o: HW_MMU_Paging.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Paging.o HW_MMU_Paging.cpp

${OBJECTDIR}/HW_MMU_Segmentation.o: HW_MMU_Segmentation.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Segmentation.o HW_MMU_Segmentation.cpp

${OBJECTDIR}/HW_Machine.o: HW_Machine.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_Machine.o HW_Machine.cpp

${OBJECTDIR}/HW_RAM.o: HW_RAM.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_RAM.o HW_RAM.cpp

${OBJECTDIR}/HW_Timer.o: HW_Timer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_Timer.o HW_Timer.cpp

${OBJECTDIR}/Mediator_CPU.o: Mediator_CPU.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_CPU.o Mediator_CPU.cpp

${OBJECTDIR}/Mediator_DMA.o: Mediator_DMA.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_DMA.o Mediator_DMA.cpp

${OBJECTDIR}/Mediator_HardDisk.o: Mediator_HardDisk.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_HardDisk.o Mediator_HardDisk.cpp

${OBJECTDIR}/Mediator_MMU.o: Mediator_MMU.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_MMU.o Mediator_MMU.cpp

${OBJECTDIR}/Mediator_Timer.o: Mediator_Timer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_Timer.o Mediator_Timer.cpp

${OBJECTDIR}/Model.o: Model.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model.o Model.cpp

${OBJECTDIR}/ModelBuilder.o: ModelBuilder.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModelBuilder.o ModelBuilder.cpp

${OBJECTDIR}/Module.o: Module.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Module.o Module.cpp

${OBJECTDIR}/ModuleCreate.o: ModuleCreate.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleCreate.o ModuleCreate.cpp

${OBJECTDIR}/ModuleDispose.o: ModuleDispose.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleDispose.o ModuleDispose.cpp

${OBJECTDIR}/ModuleInvoke_HardwareEvent.o: ModuleInvoke_HardwareEvent.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleInvoke_HardwareEvent.o ModuleInvoke_HardwareEvent.cpp

${OBJECTDIR}/ModuleInvoke_PulseExecution.o: ModuleInvoke_PulseExecution.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleInvoke_PulseExecution.o ModuleInvoke_PulseExecution.cpp

${OBJECTDIR}/NRU.o: NRU.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NRU.o NRU.cpp

${OBJECTDIR}/OperatingSystem.o: OperatingSystem.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperatingSystem.o OperatingSystem.cpp

${OBJECTDIR}/Page.o: Page.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Page.o Page.cpp

${OBJECTDIR}/PageTable.o: PageTable.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PageTable.o PageTable.cpp

${OBJECTDIR}/ProblemSolving20162ModelBuilder.o: ProblemSolving20162ModelBuilder.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProblemSolving20162ModelBuilder.o ProblemSolving20162ModelBuilder.cpp

${OBJECTDIR}/ProblemTester.o: ProblemTester.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProblemTester.o ProblemTester.cpp

${OBJECTDIR}/Simul_Debug.o: Simul_Debug.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Debug.o Simul_Debug.cpp

${OBJECTDIR}/Simul_Entity.o: Simul_Entity.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Entity.o Simul_Entity.cpp

${OBJECTDIR}/Simul_Event.o: Simul_Event.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Event.o Simul_Event.cpp

${OBJECTDIR}/Simul_Statistics.o: Simul_Statistics.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Statistics.o Simul_Statistics.cpp

${OBJECTDIR}/Simul_Util.o: Simul_Util.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Util.o Simul_Util.cpp

${OBJECTDIR}/Simulator.o: Simulator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simulator.o Simulator.cpp

${OBJECTDIR}/SourceModule.o: SourceModule.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SourceModule.o SourceModule.cpp

${OBJECTDIR}/TestApplication.o: TestApplication.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestApplication.o TestApplication.cpp

${OBJECTDIR}/Util_Queue.o: Util_Queue.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util_Queue.o Util_Queue.cpp

${OBJECTDIR}/Util_Scheduling_Queue.o: Util_Scheduling_Queue.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util_Scheduling_Queue.o Util_Scheduling_Queue.cpp

${OBJECTDIR}/VirtualMemorySwap.o: VirtualMemorySwap.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VirtualMemorySwap.o VirtualMemorySwap.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/NRUTest.o ${TESTDIR}/tests/NRUTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/MemoryManagerTest.o ${TESTDIR}/tests/MemoryManagerTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/PageTableTest.o ${TESTDIR}/tests/PageTableTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/VirtualMemorySwapTest.o ${TESTDIR}/tests/newtestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   


${TESTDIR}/tests/NRUTest.o: tests/NRUTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/NRUTest.o tests/NRUTest.cpp


${TESTDIR}/tests/NRUTestRunner.o: tests/NRUTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/NRUTestRunner.o tests/NRUTestRunner.cpp


${TESTDIR}/tests/MemoryManagerTest.o: tests/MemoryManagerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MemoryManagerTest.o tests/MemoryManagerTest.cpp


${TESTDIR}/tests/MemoryManagerTestRunner.o: tests/MemoryManagerTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MemoryManagerTestRunner.o tests/MemoryManagerTestRunner.cpp


${TESTDIR}/tests/PageTableTest.o: tests/PageTableTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/PageTableTest.o tests/PageTableTest.cpp


${TESTDIR}/tests/PageTableTestRunner.o: tests/PageTableTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/PageTableTestRunner.o tests/PageTableTestRunner.cpp


${TESTDIR}/tests/VirtualMemorySwapTest.o: tests/VirtualMemorySwapTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/VirtualMemorySwapTest.o tests/VirtualMemorySwapTest.cpp


${TESTDIR}/tests/newtestrunner.o: tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner.o tests/newtestrunner.cpp


${OBJECTDIR}/Abstr_Alarm_nomain.o: ${OBJECTDIR}/Abstr_Alarm.o Abstr_Alarm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_Alarm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Alarm_nomain.o Abstr_Alarm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_Alarm.o ${OBJECTDIR}/Abstr_Alarm_nomain.o;\
	fi

${OBJECTDIR}/Abstr_FileAllocationTable_nomain.o: ${OBJECTDIR}/Abstr_FileAllocationTable.o Abstr_FileAllocationTable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_FileAllocationTable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileAllocationTable_nomain.o Abstr_FileAllocationTable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_FileAllocationTable.o ${OBJECTDIR}/Abstr_FileAllocationTable_nomain.o;\
	fi

${OBJECTDIR}/Abstr_FileAllocator_nomain.o: ${OBJECTDIR}/Abstr_FileAllocator.o Abstr_FileAllocator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_FileAllocator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileAllocator_nomain.o Abstr_FileAllocator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_FileAllocator.o ${OBJECTDIR}/Abstr_FileAllocator_nomain.o;\
	fi

${OBJECTDIR}/Abstr_FileSystem_nomain.o: ${OBJECTDIR}/Abstr_FileSystem.o Abstr_FileSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_FileSystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileSystem_nomain.o Abstr_FileSystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_FileSystem.o ${OBJECTDIR}/Abstr_FileSystem_nomain.o;\
	fi

${OBJECTDIR}/Abstr_MemoryChunk_nomain.o: ${OBJECTDIR}/Abstr_MemoryChunk.o Abstr_MemoryChunk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_MemoryChunk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_MemoryChunk_nomain.o Abstr_MemoryChunk.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_MemoryChunk.o ${OBJECTDIR}/Abstr_MemoryChunk_nomain.o;\
	fi

${OBJECTDIR}/Abstr_MemoryManager_nomain.o: ${OBJECTDIR}/Abstr_MemoryManager.o Abstr_MemoryManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_MemoryManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_MemoryManager_nomain.o Abstr_MemoryManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_MemoryManager.o ${OBJECTDIR}/Abstr_MemoryManager_nomain.o;\
	fi

${OBJECTDIR}/Abstr_Process_nomain.o: ${OBJECTDIR}/Abstr_Process.o Abstr_Process.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_Process.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Process_nomain.o Abstr_Process.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_Process.o ${OBJECTDIR}/Abstr_Process_nomain.o;\
	fi

${OBJECTDIR}/Abstr_Scheduler_nomain.o: ${OBJECTDIR}/Abstr_Scheduler.o Abstr_Scheduler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_Scheduler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Scheduler_nomain.o Abstr_Scheduler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_Scheduler.o ${OBJECTDIR}/Abstr_Scheduler_nomain.o;\
	fi

${OBJECTDIR}/Abstr_Thread_nomain.o: ${OBJECTDIR}/Abstr_Thread.o Abstr_Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Abstr_Thread.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Thread_nomain.o Abstr_Thread.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Abstr_Thread.o ${OBJECTDIR}/Abstr_Thread_nomain.o;\
	fi

${OBJECTDIR}/Application_nomain.o: ${OBJECTDIR}/Application.o Application.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Application.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Application_nomain.o Application.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Application.o ${OBJECTDIR}/Application_nomain.o;\
	fi

${OBJECTDIR}/DataMemoryChunk_nomain.o: ${OBJECTDIR}/DataMemoryChunk.o DataMemoryChunk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DataMemoryChunk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataMemoryChunk_nomain.o DataMemoryChunk.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DataMemoryChunk.o ${OBJECTDIR}/DataMemoryChunk_nomain.o;\
	fi

${OBJECTDIR}/HW_CPU_nomain.o: ${OBJECTDIR}/HW_CPU.o HW_CPU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_CPU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_CPU_nomain.o HW_CPU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_CPU.o ${OBJECTDIR}/HW_CPU_nomain.o;\
	fi

${OBJECTDIR}/HW_DMA_nomain.o: ${OBJECTDIR}/HW_DMA.o HW_DMA.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_DMA.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_DMA_nomain.o HW_DMA.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_DMA.o ${OBJECTDIR}/HW_DMA_nomain.o;\
	fi

${OBJECTDIR}/HW_HardDisk_nomain.o: ${OBJECTDIR}/HW_HardDisk.o HW_HardDisk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_HardDisk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_HardDisk_nomain.o HW_HardDisk.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_HardDisk.o ${OBJECTDIR}/HW_HardDisk_nomain.o;\
	fi

${OBJECTDIR}/HW_MMU_nomain.o: ${OBJECTDIR}/HW_MMU.o HW_MMU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_MMU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_nomain.o HW_MMU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_MMU.o ${OBJECTDIR}/HW_MMU_nomain.o;\
	fi

${OBJECTDIR}/HW_MMU_Continuous_nomain.o: ${OBJECTDIR}/HW_MMU_Continuous.o HW_MMU_Continuous.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_MMU_Continuous.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Continuous_nomain.o HW_MMU_Continuous.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_MMU_Continuous.o ${OBJECTDIR}/HW_MMU_Continuous_nomain.o;\
	fi

${OBJECTDIR}/HW_MMU_Paging_nomain.o: ${OBJECTDIR}/HW_MMU_Paging.o HW_MMU_Paging.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_MMU_Paging.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Paging_nomain.o HW_MMU_Paging.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_MMU_Paging.o ${OBJECTDIR}/HW_MMU_Paging_nomain.o;\
	fi

${OBJECTDIR}/HW_MMU_Segmentation_nomain.o: ${OBJECTDIR}/HW_MMU_Segmentation.o HW_MMU_Segmentation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_MMU_Segmentation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Segmentation_nomain.o HW_MMU_Segmentation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_MMU_Segmentation.o ${OBJECTDIR}/HW_MMU_Segmentation_nomain.o;\
	fi

${OBJECTDIR}/HW_Machine_nomain.o: ${OBJECTDIR}/HW_Machine.o HW_Machine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_Machine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_Machine_nomain.o HW_Machine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_Machine.o ${OBJECTDIR}/HW_Machine_nomain.o;\
	fi

${OBJECTDIR}/HW_RAM_nomain.o: ${OBJECTDIR}/HW_RAM.o HW_RAM.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_RAM.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_RAM_nomain.o HW_RAM.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_RAM.o ${OBJECTDIR}/HW_RAM_nomain.o;\
	fi

${OBJECTDIR}/HW_Timer_nomain.o: ${OBJECTDIR}/HW_Timer.o HW_Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HW_Timer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_Timer_nomain.o HW_Timer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HW_Timer.o ${OBJECTDIR}/HW_Timer_nomain.o;\
	fi

${OBJECTDIR}/Mediator_CPU_nomain.o: ${OBJECTDIR}/Mediator_CPU.o Mediator_CPU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Mediator_CPU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_CPU_nomain.o Mediator_CPU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Mediator_CPU.o ${OBJECTDIR}/Mediator_CPU_nomain.o;\
	fi

${OBJECTDIR}/Mediator_DMA_nomain.o: ${OBJECTDIR}/Mediator_DMA.o Mediator_DMA.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Mediator_DMA.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_DMA_nomain.o Mediator_DMA.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Mediator_DMA.o ${OBJECTDIR}/Mediator_DMA_nomain.o;\
	fi

${OBJECTDIR}/Mediator_HardDisk_nomain.o: ${OBJECTDIR}/Mediator_HardDisk.o Mediator_HardDisk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Mediator_HardDisk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_HardDisk_nomain.o Mediator_HardDisk.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Mediator_HardDisk.o ${OBJECTDIR}/Mediator_HardDisk_nomain.o;\
	fi

${OBJECTDIR}/Mediator_MMU_nomain.o: ${OBJECTDIR}/Mediator_MMU.o Mediator_MMU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Mediator_MMU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_MMU_nomain.o Mediator_MMU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Mediator_MMU.o ${OBJECTDIR}/Mediator_MMU_nomain.o;\
	fi

${OBJECTDIR}/Mediator_Timer_nomain.o: ${OBJECTDIR}/Mediator_Timer.o Mediator_Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Mediator_Timer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_Timer_nomain.o Mediator_Timer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Mediator_Timer.o ${OBJECTDIR}/Mediator_Timer_nomain.o;\
	fi

${OBJECTDIR}/Model_nomain.o: ${OBJECTDIR}/Model.o Model.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Model.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model_nomain.o Model.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Model.o ${OBJECTDIR}/Model_nomain.o;\
	fi

${OBJECTDIR}/ModelBuilder_nomain.o: ${OBJECTDIR}/ModelBuilder.o ModelBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ModelBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModelBuilder_nomain.o ModelBuilder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ModelBuilder.o ${OBJECTDIR}/ModelBuilder_nomain.o;\
	fi

${OBJECTDIR}/Module_nomain.o: ${OBJECTDIR}/Module.o Module.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Module.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Module_nomain.o Module.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Module.o ${OBJECTDIR}/Module_nomain.o;\
	fi

${OBJECTDIR}/ModuleCreate_nomain.o: ${OBJECTDIR}/ModuleCreate.o ModuleCreate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ModuleCreate.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleCreate_nomain.o ModuleCreate.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ModuleCreate.o ${OBJECTDIR}/ModuleCreate_nomain.o;\
	fi

${OBJECTDIR}/ModuleDispose_nomain.o: ${OBJECTDIR}/ModuleDispose.o ModuleDispose.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ModuleDispose.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleDispose_nomain.o ModuleDispose.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ModuleDispose.o ${OBJECTDIR}/ModuleDispose_nomain.o;\
	fi

${OBJECTDIR}/ModuleInvoke_HardwareEvent_nomain.o: ${OBJECTDIR}/ModuleInvoke_HardwareEvent.o ModuleInvoke_HardwareEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ModuleInvoke_HardwareEvent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleInvoke_HardwareEvent_nomain.o ModuleInvoke_HardwareEvent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ModuleInvoke_HardwareEvent.o ${OBJECTDIR}/ModuleInvoke_HardwareEvent_nomain.o;\
	fi

${OBJECTDIR}/ModuleInvoke_PulseExecution_nomain.o: ${OBJECTDIR}/ModuleInvoke_PulseExecution.o ModuleInvoke_PulseExecution.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ModuleInvoke_PulseExecution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleInvoke_PulseExecution_nomain.o ModuleInvoke_PulseExecution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ModuleInvoke_PulseExecution.o ${OBJECTDIR}/ModuleInvoke_PulseExecution_nomain.o;\
	fi

${OBJECTDIR}/NRU_nomain.o: ${OBJECTDIR}/NRU.o NRU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/NRU.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NRU_nomain.o NRU.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/NRU.o ${OBJECTDIR}/NRU_nomain.o;\
	fi

${OBJECTDIR}/OperatingSystem_nomain.o: ${OBJECTDIR}/OperatingSystem.o OperatingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/OperatingSystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperatingSystem_nomain.o OperatingSystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/OperatingSystem.o ${OBJECTDIR}/OperatingSystem_nomain.o;\
	fi

${OBJECTDIR}/Page_nomain.o: ${OBJECTDIR}/Page.o Page.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Page.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Page_nomain.o Page.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Page.o ${OBJECTDIR}/Page_nomain.o;\
	fi

${OBJECTDIR}/PageTable_nomain.o: ${OBJECTDIR}/PageTable.o PageTable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PageTable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PageTable_nomain.o PageTable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PageTable.o ${OBJECTDIR}/PageTable_nomain.o;\
	fi

${OBJECTDIR}/ProblemSolving20162ModelBuilder_nomain.o: ${OBJECTDIR}/ProblemSolving20162ModelBuilder.o ProblemSolving20162ModelBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProblemSolving20162ModelBuilder.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProblemSolving20162ModelBuilder_nomain.o ProblemSolving20162ModelBuilder.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProblemSolving20162ModelBuilder.o ${OBJECTDIR}/ProblemSolving20162ModelBuilder_nomain.o;\
	fi

${OBJECTDIR}/ProblemTester_nomain.o: ${OBJECTDIR}/ProblemTester.o ProblemTester.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProblemTester.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProblemTester_nomain.o ProblemTester.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProblemTester.o ${OBJECTDIR}/ProblemTester_nomain.o;\
	fi

${OBJECTDIR}/Simul_Debug_nomain.o: ${OBJECTDIR}/Simul_Debug.o Simul_Debug.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Simul_Debug.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Debug_nomain.o Simul_Debug.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Simul_Debug.o ${OBJECTDIR}/Simul_Debug_nomain.o;\
	fi

${OBJECTDIR}/Simul_Entity_nomain.o: ${OBJECTDIR}/Simul_Entity.o Simul_Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Simul_Entity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Entity_nomain.o Simul_Entity.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Simul_Entity.o ${OBJECTDIR}/Simul_Entity_nomain.o;\
	fi

${OBJECTDIR}/Simul_Event_nomain.o: ${OBJECTDIR}/Simul_Event.o Simul_Event.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Simul_Event.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Event_nomain.o Simul_Event.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Simul_Event.o ${OBJECTDIR}/Simul_Event_nomain.o;\
	fi

${OBJECTDIR}/Simul_Statistics_nomain.o: ${OBJECTDIR}/Simul_Statistics.o Simul_Statistics.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Simul_Statistics.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Statistics_nomain.o Simul_Statistics.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Simul_Statistics.o ${OBJECTDIR}/Simul_Statistics_nomain.o;\
	fi

${OBJECTDIR}/Simul_Util_nomain.o: ${OBJECTDIR}/Simul_Util.o Simul_Util.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Simul_Util.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Util_nomain.o Simul_Util.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Simul_Util.o ${OBJECTDIR}/Simul_Util_nomain.o;\
	fi

${OBJECTDIR}/Simulator_nomain.o: ${OBJECTDIR}/Simulator.o Simulator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Simulator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simulator_nomain.o Simulator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Simulator.o ${OBJECTDIR}/Simulator_nomain.o;\
	fi

${OBJECTDIR}/SourceModule_nomain.o: ${OBJECTDIR}/SourceModule.o SourceModule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SourceModule.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SourceModule_nomain.o SourceModule.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SourceModule.o ${OBJECTDIR}/SourceModule_nomain.o;\
	fi

${OBJECTDIR}/TestApplication_nomain.o: ${OBJECTDIR}/TestApplication.o TestApplication.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TestApplication.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestApplication_nomain.o TestApplication.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TestApplication.o ${OBJECTDIR}/TestApplication_nomain.o;\
	fi

${OBJECTDIR}/Util_Queue_nomain.o: ${OBJECTDIR}/Util_Queue.o Util_Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util_Queue.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util_Queue_nomain.o Util_Queue.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util_Queue.o ${OBJECTDIR}/Util_Queue_nomain.o;\
	fi

${OBJECTDIR}/Util_Scheduling_Queue_nomain.o: ${OBJECTDIR}/Util_Scheduling_Queue.o Util_Scheduling_Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Util_Scheduling_Queue.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util_Scheduling_Queue_nomain.o Util_Scheduling_Queue.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Util_Scheduling_Queue.o ${OBJECTDIR}/Util_Scheduling_Queue_nomain.o;\
	fi

${OBJECTDIR}/VirtualMemorySwap_nomain.o: ${OBJECTDIR}/VirtualMemorySwap.o VirtualMemorySwap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VirtualMemorySwap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VirtualMemorySwap_nomain.o VirtualMemorySwap.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/VirtualMemorySwap.o ${OBJECTDIR}/VirtualMemorySwap_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
