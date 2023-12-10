import sys, os
from bs4 import BeautifulSoup

def swapBoldCode(article):
    # Swap bold tags inside code tags
    # In markdown everything inside the backticks is considered as code
    # and it is not parsed as markdown
    for tag in article.find_all('code'):
        em = tag.find('em')
        if em:
            newEm = soup.new_tag('code')
            newEm.string = em.text
            newTag = soup.new_tag('em')
            newTag.append(newEm)
            tag.replaceWith(newTag)

def replaceBold(article):
    for tag in article.find_all('em'):
        tag.insert_before('**')
        tag.insert_after('**')

def replaceCode(article):
    for tag in article.find_all('code'):
        l = '`'
        r = '`'
        if tag.parent.name == 'pre':
            l = '\n```\n'
            r = '```\n'
        tag.insert_before(l)
        tag.insert_after(r)

def replaceList(article):
    for tag in article.find_all('li'):
        tag.insert_before('- ')

def replaceUrl(article):
    for tag in article.find_all('a', href=True):
        tag.insert_before('[')
        tag.insert_after(f"]({tag['href']})")


def htmlToMd(html):    
    swapBoldCode(html)

    replaceBold(html)
    replaceCode(html)
    replaceList(html)
    replaceUrl(html)

    return html.text


# Get some SOUP!!!
with open('page.html', 'r') as f:
    html = f.read()
soup = BeautifulSoup(html, 'html.parser')

md = ""

# Title
title = soup.find('h2').text.replace("---", "").strip()
md += f"# {title}\n\n## Part One\n\n"

# Get two parts
descriptions = soup.find_all('article')

# Part one
first = descriptions[0]
first.find('h2').extract() # Remove title

md += htmlToMd(first)

# Part two
second = descriptions[1]
second.find('h2').extract() # Remove title

md += "\n## Part Two\n\n"
md += htmlToMd(second)

md += "\n"

with open('page.md', 'w') as f:
    f.write(md)
