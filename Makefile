CC			=	gcc
CC_FLAGS 	=	-g -I. -W -Wall -Werror
LD_FLAGS	=	-lpthread -luv
EXEC		=	evnt_srv
SOURCES		=	$(wildcard *.c)
HEADERS		=	$(wildcard *.h)
OBJECTS		=	$(BUILD_DIR)/$(SOURCES:.c=.o)
BUILD_DIR	=	./build

all: directories evnt_srv  

directories: 
	mkdir -p $(BUILD_DIR)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(LD_FLAGS) -o $(BUILD_DIR)/$(EXEC)

# To obtain object files
$(BUILD_DIR)/%.o: %.c $(HEADERS)
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -rf core $(BUILD_DIR)
