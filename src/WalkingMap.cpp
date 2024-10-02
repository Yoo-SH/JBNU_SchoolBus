#include "WalkingMap.h"



	WalkingMap :: WalkingMap(string starting_location)
	{

		if (starting_location == "공대7호관")
		{

			schoolMap["생활관"] = WalkingTime::from공대7호관to생활관;
			schoolMap["예체능관"] = WalkingTime::from공대7호관to예체능관;
			schoolMap["2학생회관"] = WalkingTime::from공대7호관to2학생회관;
			schoolMap["진수당"] = WalkingTime::from공대7호관to진수당;
			schoolMap["대학본부"] = WalkingTime::from공대7호관to대학본부;
			schoolMap["정보전산원"] = WalkingTime::from공대7호관to정보전산원;
			schoolMap["치의학전문대학원"] = WalkingTime::from공대7호관to치의학전문대학원;
			schoolMap["간호대학"] = WalkingTime::from공대7호관to간호대학;
			schoolMap["생활대"] = WalkingTime::from공대7호관to생활대;
			schoolMap["상대2호관"] = WalkingTime::from공대7호관to상대2호관;
			schoolMap["학습도서관"] = WalkingTime::from공대7호관to학습도서관;
			schoolMap["농생대본관"] = WalkingTime::from공대7호관to농생대본관;

			schoolMap["중앙도서관"] = WalkingTime::from공대7호관to중앙도서관;

			//자료 추가 필요 다른 건물 27개
		}
		else if(starting_location == "중앙도서관")
		{

			schoolMap["생활관"] = WalkingTime::from중앙도서관to생활관;
			schoolMap["예체능관"] = WalkingTime::from중앙도서관to예체능관;
			schoolMap["2학생회관"] = WalkingTime::from중앙도서관to2학생회관;
			schoolMap["진수당"] = WalkingTime::from중앙도서관to진수당;
			schoolMap["대학본부"] = WalkingTime::from중앙도서관to대학본부;
			schoolMap["정보전산원"] = WalkingTime::from중앙도서관to정보전산원;
			schoolMap["치의학전문대학원"] = WalkingTime::from중앙도서관to치의학전문대학원;
			schoolMap["간호대학"] = WalkingTime::from중앙도서관to간호대학;
			schoolMap["생활대"] = WalkingTime::from중앙도서관to생활대;
			schoolMap["상대2호관"] = WalkingTime::from중앙도서관to상대2호관;
			schoolMap["학습도서관"] = WalkingTime::from중앙도서관to학습도서관;
			schoolMap["농생대본관"] = WalkingTime::from중앙도서관to농생대본관;

		}
		// 출발지점 자료 추가 필요 

	}

