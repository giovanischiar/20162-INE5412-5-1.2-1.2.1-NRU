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
CND_CONF=Release
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
	${OBJECTDIR}/OperatingSystem.o \
	${OBJECTDIR}/ProblemSolving20162ModelBuilder.o \
	${OBJECTDIR}/ProblemTester.o \
	${OBJECTDIR}/Simul_Debug.o \
	${OBJECTDIR}/Simul_Entity.o \
	${OBJECTDIR}/Simul_Event.o \
	${OBJECTDIR}/Simul_Statistics.o \
	${OBJECTDIR}/Simul_Util.o \
	${OBJECTDIR}/Simulator.o \
	${OBJECTDIR}/SourceModule.o \
	${OBJECTDIR}/Util_Queue.o \
	${OBJECTDIR}/Util_Scheduling_Queue.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20162-ine5412-sc-theme1-startpoint

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20162-ine5412-sc-theme1-startpoint: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20162-ine5412-sc-theme1-startpoint ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Abstr_Alarm.o: Abstr_Alarm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Alarm.o Abstr_Alarm.cpp

${OBJECTDIR}/Abstr_FileAllocationTable.o: Abstr_FileAllocationTable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileAllocationTable.o Abstr_FileAllocationTable.cpp

${OBJECTDIR}/Abstr_FileAllocator.o: Abstr_FileAllocator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileAllocator.o Abstr_FileAllocator.cpp

${OBJECTDIR}/Abstr_FileSystem.o: Abstr_FileSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_FileSystem.o Abstr_FileSystem.cpp

${OBJECTDIR}/Abstr_MemoryChunk.o: Abstr_MemoryChunk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_MemoryChunk.o Abstr_MemoryChunk.cpp

${OBJECTDIR}/Abstr_MemoryManager.o: Abstr_MemoryManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_MemoryManager.o Abstr_MemoryManager.cpp

${OBJECTDIR}/Abstr_Process.o: Abstr_Process.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Process.o Abstr_Process.cpp

${OBJECTDIR}/Abstr_Scheduler.o: Abstr_Scheduler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Scheduler.o Abstr_Scheduler.cpp

${OBJECTDIR}/Abstr_Thread.o: Abstr_Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abstr_Thread.o Abstr_Thread.cpp

${OBJECTDIR}/Application.o: Application.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Application.o Application.cpp

${OBJECTDIR}/HW_CPU.o: HW_CPU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_CPU.o HW_CPU.cpp

${OBJECTDIR}/HW_DMA.o: HW_DMA.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_DMA.o HW_DMA.cpp

${OBJECTDIR}/HW_HardDisk.o: HW_HardDisk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_HardDisk.o HW_HardDisk.cpp

${OBJECTDIR}/HW_MMU.o: HW_MMU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU.o HW_MMU.cpp

${OBJECTDIR}/HW_MMU_Continuous.o: HW_MMU_Continuous.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Continuous.o HW_MMU_Continuous.cpp

${OBJECTDIR}/HW_MMU_Paging.o: HW_MMU_Paging.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Paging.o HW_MMU_Paging.cpp

${OBJECTDIR}/HW_MMU_Segmentation.o: HW_MMU_Segmentation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_MMU_Segmentation.o HW_MMU_Segmentation.cpp

${OBJECTDIR}/HW_Machine.o: HW_Machine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_Machine.o HW_Machine.cpp

${OBJECTDIR}/HW_RAM.o: HW_RAM.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_RAM.o HW_RAM.cpp

${OBJECTDIR}/HW_Timer.o: HW_Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HW_Timer.o HW_Timer.cpp

${OBJECTDIR}/Mediator_CPU.o: Mediator_CPU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_CPU.o Mediator_CPU.cpp

${OBJECTDIR}/Mediator_DMA.o: Mediator_DMA.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_DMA.o Mediator_DMA.cpp

${OBJECTDIR}/Mediator_HardDisk.o: Mediator_HardDisk.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_HardDisk.o Mediator_HardDisk.cpp

${OBJECTDIR}/Mediator_MMU.o: Mediator_MMU.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_MMU.o Mediator_MMU.cpp

${OBJECTDIR}/Mediator_Timer.o: Mediator_Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mediator_Timer.o Mediator_Timer.cpp

${OBJECTDIR}/Model.o: Model.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model.o Model.cpp

${OBJECTDIR}/ModelBuilder.o: ModelBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModelBuilder.o ModelBuilder.cpp

${OBJECTDIR}/Module.o: Module.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Module.o Module.cpp

${OBJECTDIR}/ModuleCreate.o: ModuleCreate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleCreate.o ModuleCreate.cpp

${OBJECTDIR}/ModuleDispose.o: ModuleDispose.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleDispose.o ModuleDispose.cpp

${OBJECTDIR}/ModuleInvoke_HardwareEvent.o: ModuleInvoke_HardwareEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleInvoke_HardwareEvent.o ModuleInvoke_HardwareEvent.cpp

${OBJECTDIR}/ModuleInvoke_PulseExecution.o: ModuleInvoke_PulseExecution.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleInvoke_PulseExecution.o ModuleInvoke_PulseExecution.cpp

${OBJECTDIR}/OperatingSystem.o: OperatingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OperatingSystem.o OperatingSystem.cpp

${OBJECTDIR}/ProblemSolving20162ModelBuilder.o: ProblemSolving20162ModelBuilder.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProblemSolving20162ModelBuilder.o ProblemSolving20162ModelBuilder.cpp

${OBJECTDIR}/ProblemTester.o: ProblemTester.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProblemTester.o ProblemTester.cpp

${OBJECTDIR}/Simul_Debug.o: Simul_Debug.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Debug.o Simul_Debug.cpp

${OBJECTDIR}/Simul_Entity.o: Simul_Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Entity.o Simul_Entity.cpp

${OBJECTDIR}/Simul_Event.o: Simul_Event.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Event.o Simul_Event.cpp

${OBJECTDIR}/Simul_Statistics.o: Simul_Statistics.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Statistics.o Simul_Statistics.cpp

${OBJECTDIR}/Simul_Util.o: Simul_Util.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simul_Util.o Simul_Util.cpp

${OBJECTDIR}/Simulator.o: Simulator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simulator.o Simulator.cpp

${OBJECTDIR}/SourceModule.o: SourceModule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SourceModule.o SourceModule.cpp

${OBJECTDIR}/Util_Queue.o: Util_Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util_Queue.o Util_Queue.cpp

${OBJECTDIR}/Util_Scheduling_Queue.o: Util_Scheduling_Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util_Scheduling_Queue.o Util_Scheduling_Queue.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/20162-ine5412-sc-theme1-startpoint

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
