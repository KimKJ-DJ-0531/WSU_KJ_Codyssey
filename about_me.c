#include <stdio.h>
#include <string.h>


int main(void)
{
    struct Member
    {
        char *name;
        char *gender;
        char *major;
        int years;
        char *rule;
        char *skills;
        char introduction[1024]; // strtok는 포인터로 선언된 char배열을 나누지 못함(읽기 전용 메모리에 저장되기 때문)
    };

    struct Member Arthur_Dent = {"아서덴트", "남", "기계 공학", 15, "아키텍트", "C/C++, 자바, 스프링, 파이썬, 머신러닝/딥러닝", "실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다. 성공과 실패를 겪으며 얻게 된 깨달음을 여러분과 나누고 싶습니다."};
    struct Member Kim_Yeong_Jin = {"김영진", "남", "컴퓨터 공학", 2, "개발자", "C#, 파이썬, 자바스크립트, 리액트, 코틀린", "최근에 MAUI 프레임워크로 진행한 개인 자산 관리 프로젝트에서 소프트웨어 개발에 엄청난 매력을 느꼈습니다. 나의 코드로 현실의 문제를 해결한다니! 마그라테아를 성공적으로 개발하는 것은 저의 버킷 리스트 중 하나가 되었습니다."};
    struct Member Lim_One_Chul = {"임원철", "남", "전자 공학", 1, "DBA", "자바, PHP, Mongo DB, MS SQL, MySQL", "애플리케이션은 결국 데이터를 다루는 방식을 구현한 것이라고 생각합니다. 대학에서 컴퓨터 공학과의 빅데이터 과목을 수강하며 데이터 플랫폼에 관해 매력을 느꼈습니다. 이번 프로젝트의 성공 여부는 데이터에 달렸다고 생각합니다. 마그라테아에서 다룰 데이터를 생각하면 벌써 부터 흥분됩니다."};
    struct Member You_Go_Eun = {"유고은", "여", "경영 정보", 1, "클라우드", "자바, PowerShell, Azure, AWS, GCP", "김영진님과 함께 프로젝트를 진행했으며 클라우드 아키텍처 구현을 담당했습니다. 학창시절 클라우드에 매력을 느껴 마이크로소프트 Azure에 빠져들었는데, 깊이 탐구하다보니 다른 퍼블릭 클라우드도 어렵지 않게 이해할 수 있었습니다. 마그라테아의 클라우드 아키텍처를 내 손으로 꼭 완성시키고 싶습니다."};
    struct Member Seo_Hae_Gyeong = {"서혜경", "여", "정치 외교", 0, "개발자", "파이썬, 스위프트, 코틀린, Node.js, 피그마", "학부과정에서 과제로 프로젝트는 많이 진행해봤지만, 기업의 사활이 걸린 실전 프로젝트는 제 인생의 첫 경험입니다. 이 프로젝트에 참여하게 되어 기대도 많이 되는 한편으로, 제가 잘할 수 있을까 염려가 되기도 합니다. 마그라테아 프로젝트에 관해 들었을 때 제 속에서 이 프로젝트는 인생을 걸고 싶다는 생각을 했습니다. 링크드인을 통해 이미 아서님의 명성을 접했던 터라, 이번 프로젝트에 함께할 수 있어서 영광입니다."};

    struct Member members[10] = {Arthur_Dent, Kim_Yeong_Jin, Lim_One_Chul, You_Go_Eun, Seo_Hae_Gyeong};

    printf("[마그라테아] ❤❤ 프로젝트 멤버 소개 ❤❤\n");
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

    for (int i = 0; i < 10; i++)
    {
        if (members[i].name == NULL)
            continue;

        printf("이름 | %s\t\t", members[i].name);
        printf("성별 | %s\n", members[i].gender);
        printf("전공 | %s\t", members[i].major);

        printf("경력 | ");

        // 경력을 2진수로 표현하기
        // 10000000 00000000 00000000 00000000 (2) 부터 비트 체크를 함
        // 각 자리수마다 비트가 우측으로 옮겨져서 체크
        unsigned int INT_BIT = 0x80000000;

        for (int j = 0; j < 32; j++)
        {
            if (members[i].years == 0)
            {
                printf("00000000 00000000 00000000 00000000");
                break;
            }

            if (j != 0 && (j % 8) == 0)
            {
                printf(" ");
            }

            if ((members[i].years & INT_BIT) == INT_BIT)
                printf("1");
            else
                printf("0");

            INT_BIT >>= 1;
        }
        printf("(2)\n");

        printf("역할 | %s\t\t", members[i].rule);
        printf("기술 | %s\n", members[i].skills);
        printf("------------------------------------------------------\n");
        printf("소개 | ");

        // 문자열 자르기
        // 문자열 "."을 기준으로 정적 문자열 배열 introduction을 자름
        char *temp = strtok(members[i].introduction, ".");

        // 개행을 맞추기 위한 count 변수
        int count = 0;

        while (temp != NULL)
        {
            if (count > 0)
                printf("\t%s.\n", temp);
            else
                printf("%s.\n", temp);
            temp = strtok(NULL, ".");
            count++;
        }

        printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
    }

    return 0;
}
