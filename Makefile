CC          = gcc
LD          = gcc 
CFLAG       = -g -W -Wall -Werror
LDFLAG      = -lpthread -luv
PROG_NAME   = evnt_srvr

SRC_DIR     = 
BUILD_DIR   = ./build
BIN_DIR     = 
SRC_LIST	= $(wildcard $(SRC_DIR)/*.c)
HEADERS		= $(wildcard $(SRC_DIR)/*.h)
OBJ_LIST	= $(BUILD_DIR)/$(notdir $(SRC_LIST:.c=.o))

.PHONY: all clean $(PROG_NAME) compile

all: $(PROG_NAME)

compile: 
	$(CC) $(OBJ_LIST) $(LDFLAG) -o $(OBJ_LIST)$(PROG_NAME)

$(PROG_NAME): compile
	$(LD) $(OBJ_LIST) -o $(BUILD_DIR)/$@

clean:
	rm -f $(BUILD_DIR)/$(PROG_NAME) $(BUILD_DIR)/*.o

