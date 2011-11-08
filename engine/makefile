# Specify the main target
TARGET = engine_test
# Default build type
TYPE = debug
# Which directories contain source files
DIRS = . graphics/src input/src
# Which libraries are linked
LIBS = SDL SDL_image SDL_ttf pthread
# Dynamic libraries
DLIBS =

# The next blocks change some variables depending on the build type
ifeq ($(TYPE),debug)
LDPARAM = 
CCPARAM = -Wall -g
MACROS =
endif

ifeq ($(TYPE),profile)
LDPARAM = -pg /lib/libc.so.5
CCPARAM = -Wall -pg
MACROS = NDEBUG
endif

ifeq ($(TYPE), release)
LDPARAM = -s
CCPARAM = -Wall -O2
MACROS = NDEBUG
endif

# Add directories to the include and library paths
INCPATH = . graphics/inc input/inc
LIBPATH = 

# Which files to add to backups, apart from the source code
EXTRA_FILES = Makefile
# The compiler
C++ = g++

# Where to store object and dependancy files.
STORE = .make-$(TYPE)
# Makes a list of the source (.cpp) files.
SOURCE := $(foreach DIR,$(DIRS),$(wildcard $(DIR)/*.cpp))
# List of header files.
HEADERS := $(foreach DIR,$(DIRS),$(wildcard $(DIR)/*.hpp))
# Makes a list of the object files that will have to be created.
OBJECTS := $(addprefix $(STORE)/, $(SOURCE:.cpp=.o))
# Same for the .d (dependancy) files.
DFILES := $(addprefix $(STORE)/,$(SOURCE:.cpp=.d))

# Specify phony rules. These are rules that are not real files.
.PHONY: clean backup dirs

# Main target. The @ in front of a command prevents make from displaying
# it to the standard output.
all: dirs $(OBJECTS)
	@echo Linking $(TARGET).
	@$(C++) -o $(TARGET) $(OBJECTS) $(LDPARAM) $(foreach LIBRARY, \
                $(LIBS),-l$(LIBRARY)) $(foreach LIB,$(LIBPATH),-L$(LIB))

# Rule for creating object file and .d file, the sed magic is to add
# the object path at the start of the file because the files gcc
# outputs assume it will be in the same dir as the source file.
$(STORE)/%.o: %.cpp
	@echo Creating object file for $*...
	@$(C++) -Wp,-MMD,$(STORE)/$*.dd $(CCPARAM) $(foreach INC,$(INCPATH),-I$(INC))\
            $(foreach MACRO,$(MACROS),-D$(MACRO)) -c $< -o $@
	@sed -e '1s/^\(.*\)$$/$(subst /,\/,$(dir $@))\1/' $(STORE)/$*.dd > $(STORE)/$*.d
	@rm -f $(STORE)/$*.dd

# Empty rule to prevent problems when a header is deleted.
%.hpp: ;

# Cleans up the objects, .d files and executables.
clean:
	@echo Making clean.
	@-rm -f $(foreach DIR,$(DIRS),$(STORE)/$(DIR)/*.d $(STORE)/$(DIR)/*.o)
	@-rm -f $(TARGET)

# Backup the source files.
backup:
	@-if [ ! -e .backup ]; then mkdir .backup; fi;
	@zip .backup/backup_`date +%d-%m-%y_%H.%M`.zip $(SOURCE) $(HEADERS) $(EXTRA_FILES)

# Create necessary directories
dirs:
	@-if [ ! -e $(STORE) ]; then mkdir $(STORE); fi;
	@-$(foreach DIR,$(DIRS), if [ ! -e $(STORE)/$(DIR) ]; \
         then mkdir  -p $(STORE)/$(DIR); fi; )

# Includes the .d files so it knows the exact dependencies for every
# source.
-include $(DFILES)
