import os
import re
import requests

LEETCODE_API = "https://leetcode.com/graphql"

def get_question_data(title):
    query = """
    query getQuestion($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionId
        title
        titleSlug
        difficulty
      }
    }
    """

    slug = title.lower().replace(" ", "-")

    variables = {"titleSlug": slug}

    response = requests.post(
        LEETCODE_API,
        json={"query": query, "variables": variables},
    )

    data = response.json()

    if "data" in data and data["data"]["question"]:
        return data["data"]["question"]

    return None


def smart_slug(title):
    # fallback: basic slug
    return title.lower().replace(" ", "-")


files = [f for f in os.listdir('.') if f.endswith('.cpp')]

problems = []

for f in files:
    match = re.match(r"(\d+)\.\s+(.+)\.cpp", f)
    if match:
        num = match.group(1)
        title = match.group(2).strip()

        slug = smart_slug(title)
        data = get_question_data(slug)

        if data:
            slug = data["titleSlug"]
            difficulty = data["difficulty"]
        else:
            difficulty = "Unknown"

        url = f"https://leetcode.com/problems/{slug}/"

        problems.append((int(num), num, title, url, difficulty, f))

# 排序
problems.sort()

# 產生 README
lines = ["# LeetCode Solutions\n"]

lines.append("| # | Title | Difficulty | Code |")
lines.append("|---|------|------------|------|")

for _, num, title, url, difficulty, filename in problems:
    lines.append(
        f"| {num} | [{title}]({url}) | {difficulty} | [Link](./{filename}) |"
    )

with open("README.md", "w") as f:
    f.write("\n".join(lines))
