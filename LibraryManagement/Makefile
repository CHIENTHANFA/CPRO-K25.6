TARGET = library_app

OBJ = main.o \
      Book/book.o \
      User/user.o \
      Utils/utils.o \
      Management/management.o

# Quy tắc build chương trình
all:
	@echo "Biên dịch các file..."
	gcc -c -o main.o main.c
	gcc -c -o Book/book.o Book/book.c
	gcc -c -o User/user.o User/user.c
	gcc -c -o Utils/utils.o Utils/utils.c
	gcc -c -o Management/management.o Management/management.c
	gcc -o $(TARGET) main.o Book/book.o User/user.o Utils/utils.o Management/management.o
	@echo "Build hoàn tất! Chạy chương trình bằng ./$(TARGET)"

# Quy tắc dọn dẹp
clean:
	rm -f $(OBJ) $(TARGET)
	@echo "Đã xóa các file .o và chương trình build!"
