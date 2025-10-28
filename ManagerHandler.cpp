#include "ManagerHandler.h"
#include "ManagerHandler.h"
#include "Issue.h"

#include <iostream>

bool ManagerHandler::canHandle(Issue *issue)
{
    std::string id = issue->getID();
    return (id == "Manager" || id == "Escalated" || id == "Staff");
}

void ManagerHandler::processIssue(Issue *issue)
{
    std::cout << "ManagerHandler processing: "
              << issue->getDescription() << std::endl;

    std::string issueType = issue->getID();

    if (issueType == "Staff")
    {
        std::cout << "Addressing staff-related matter..." << std::endl;
        std::cout << "Scheduling performance review." << std::endl;
    }
    else if (issueType == "Escalated")
    {
        std::cout << "Reviewing escalated complaint..." << std::endl;
        std::cout << "Contacting customer directly." << std::endl;
    }
    else
    {
        std::cout << "Handling management decision..." << std::endl;
    }

    std::cout << "Manager issue resolved with authority.\n"
              << std::endl;
}
ManagerHandler ::ManagerHandler()
{
}

ManagerHandler ::~ManagerHandler()
{
}