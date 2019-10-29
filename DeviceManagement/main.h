#pragma once

int main(void);

std::string testCreationWithBuilder(void);

std::string testCreationWithoutBuilder(void);

std::shared_ptr<csk::Room> testParsing(std::string &jsonString);