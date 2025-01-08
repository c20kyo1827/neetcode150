import os

def generate_readme(output_file):
    # 過濾出數字開頭的檔案
    files = [f for f in os.listdir('.') if f.split('.')[0].isdigit() and f != "README.md"]
    problems = []
    for file in files:
        number = int(file.split('.')[0])  # 提取檔案名稱中的數字
        problems.append((number, file))

    # 按數字排序
    problems.sort()

    # 生成 README 的內容
    with open(output_file, 'w') as readme:
        readme.write("# LeetCode Solutions\n\n")
        readme.write("## Problems List\n\n")
        for number, file in problems:
            title = file.split('.', 1)[1].replace('-', ' ').replace('.cpp', '').strip()
            readme.write(f"{number}. [{title}]({file})\n")

# 用於 GitHub Actions 的執行點
if __name__ == "__main__":
    generate_readme('README.md')
