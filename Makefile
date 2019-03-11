CC			=	gcc
CC_FLAGS 	=	-g -I. -W -Wall -Werror
LD_FLAGS	=	-lpthread -luv
EXEC		=	evnt_srv
BUILD_DIR	=	./build
SOURCES		=	$(wildcard *.c)
HEADERS		=	$(wildcard *.h)
OBJECTS		=	$(SOURCES:.c=.o)

all: directories $(EXEC)

directories:
	mkdir -p $(BUILD_DIR)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(CC_FLAGS) $(BUILD_DIR)/*.o $(LD_FLAGS) -o $(BUILD_DIR)/$(EXEC)

# To obtain object files
%.o: %.c $(HEADERS)
	$(CC) $(CC_FLAGS) -c  $< -o $(BUILD_DIR)/$@

# To remove generated files
clean:
	rm -rf core $(BUILD_DIR)
