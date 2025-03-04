# Báo cáo Bài tập lớn - Nhóm 6

## 1. Thông tin nhóm
| STT | Họ và tên | MSSV | Vai trò |
|---|---|---|---|
| 1 | Vũ Tuấn Anh | 24022766 | Nhóm trưởng |
| 2 |Trần Anh Khoa | 24022806| Thành viên |
| 3 | Nguyễn Vũ Đức Anh | 24022765 | Thành viên |
| 4 | Nguyễn Khắc Huy | 24022802 | Thành viên |
| 5 | Lương Hiển Long | 24022810 | Thành viên |
---

## 2. Thông tin bài tập
- **Tên bài toán**: Cho bảng Sudoku 9x9. Một số ô đã điền số. Dùng đệ quy + quay lui để điền đủ bảng.


---

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
Bài toán yêu cầu ta giải một bảng Sudoku 9x9 có một số ô đã được điền số vào.
Yêu cầu đầu vào:
Đầu vào của bài toán: Một dãy các chữ số nhập vào bảng sudoku theo dạng một ô vuông 9x9. Mỗi dòng gồm 9 chữ số được đánh số từ 0 đến 9 (Nếu có ô trống thì để số 0) cách nhau bằng dấu cách.
Ràng buộc của đầu vào: Bảng Sudoku không có phương án khả thi hoặc chỉ có một phương án duy nhất thỏa mãn.

### b. Thuật toán/Hướng tiếp cận
Sử dụng đệ quy và backtracking
Ý tưởng: Thay lần lần từng ô trống bằng các số từ 1 đến 9. Nếu thỏa mãn điều kiện của hàng dọc, ngang và ô 3x3 thì chuyển tới ô tiếp theo, lần lượt duyệt qua toàn bộ các ô và trả về kết quả bảng sudoku đã điền. Nếu không thỏa mãn, lùi về ô đã điền lúc trước và thay số khác. Nếu lùi tới ô đầu tiên điền và thay toàn bộ các số từ 1 đến 9 nhưng không thỏa mãn, trả về thông báo sudoku không thỏa mãn.

---

## 4. Ví dụ minh hoạ
### Ví dụ 1
**Input:**  
2 5 6 4 8 9 1 7 3  
3 7 4 6 1 5 9 8 2  
9 8 1 7 2 3 4 5 6  
5 9 3 2 7 4 8 6 1  
7 1 2 8 0 6 5 4 9  
4 6 8 5 9 1 3 2 7  
6 3 5 1 4 7 2 9 8  
1 2 7 9 5 8 6 3 4  
8 4 9 3 6 2 7 1 5  
**Output:**  
Solved Sudoku:
2 5 6 4 8 9 1 7 3  
3 7 4 6 1 5 9 8 2  
9 8 1 7 2 3 4 5 6  
5 9 3 2 7 4 8 6 1  
7 1 2 8 0 6 5 4 9  
4 6 8 5 9 1 3 2 7  
6 3 5 1 4 7 2 9 8  
1 2 7 9 5 8 6 3 4  
8 4 9 3 6 2 7 1 5  
**Giải thích:**  
Đầu vào của mình là một bảng Sudoku đã có đầy đủ các số trong các ô ==> Nếu đúng thì đầu ra của mình sẽ in ra là Solved Sudoku và in lại cái bảng Sudoku đó.

### Ví dụ 2
**Input:**  
0 0 2 0 3 0 0 0 8  
0 0 0 0 0 8 0 0 0  
0 3 1 0 2 0 0 0 0  
0 6 0 0 5 0 2 7 0  
0 1 0 0 0 0 0 5 0  
2 0 4 0 6 0 0 3 1  
0 0 0 0 8 0 6 0 5  
0 0 0 0 0 0 0 1 3  
0 0 5 3 1 0 4 0 0     
**Output:**  
Solved Sudoku:  
6 7 2 4 3 5 1 9 8   
5 4 9 1 7 8 3 6 2   
8 3 1 6 2 9 5 4 7   
3 6 8 9 5 1 2 7 4   
9 1 7 2 4 3 8 5 6   
2 5 4 8 6 7 9 3 1   
1 9 3 7 8 4 6 2 5   
4 8 6 5 9 2 7 1 3  
7 2 5 3 1 6 4 8 9    
**Giải thích:**  
Đầu vào của mình là một bảng Sudoku có một số ô vẫn còn trống (ô có giá trị 0) ==> Nên sau khi sử dụng thuật toán backtracking thì sẽ thực hiện giải bảng Sudoku trên và in ra kết quả là một bảng Sudokuu đã hoàn chỉnh.

### Ví dụ 3
**Input:**  
0 0 9 0 7 0 0 0 5  
0 0 2 1 0 0 9 0 0  
1 0 0 0 2 8 0 0 0  
0 7 0 0 0 5 0 0 1  
0 0 8 5 1 0 0 0 0  
0 5 0 0 0 0 3 0 0  
0 0 0 0 0 3 0 0 6  
8 0 0 0 0 0 0 0 0  
2 1 0 0 0 0 0 8 7    
**Output:**  
Solved Sudoku:  
Invalid Sudoku  
**Giải thích:**  
Đầu vào của mình là một bảng Sudoku có một số ô vẫn còn trống (ô có giá trị 0) ==> Sau khi sử dụng thuật toán backtracking và phát hiện ra lỗi là không có đáp án hợp lệ thì sẽ in ra kết quả là "Invalid" ==> Đầu vào mình nhập là một bảng Sudoku không giải được.

---

## 5. Link video báo cáo
[Video báo cáo nhóm X](#)

---

## 6. Link source code
[Thư mục src](./src)

