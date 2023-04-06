# <span style="color:yellow">자료구조 요약 정리</span>

### CH#1. 기본개념
***
>자료구조의 역할, 왜 중요한가?

- 알고리즘은 답이 없는 문제를 다루지 않는다.
- 최적의 해를 찾는 것이 핵심이다.
- 알고리즘의 최적의 해는 <span style="color:yellow">자료구조의 영향을 받는다</span>(비용, 시간적으로)

>시스템 생명 주기

- 요구사항(requirement)<br>
  - 프로젝트들의 목적을 정의한 명세들의 집합
  - 입력과 출력에 관한 정보 기술
- 분석(analysis)
  - 문제들을 작은 단위로 나눔
  - 상향식/하향식 접근 방법
- 설계(design)
  - 추상 데이터 타입(ADT) 생성
  - 알고리즘 명세와 설계 기법 고려
- 정제와 코딩(refunement and coding)
  - 데이터 객체에 대한 표현 선택
  - 수행되는 연산에 대한 알고리즘 작성
- 검증(verfication)
  - 정확성 증명
    - 수학적 기법들을 이용해서 증명
    - 어려운 일, 대형 프로젝트에 적용 어려움
  - 테스트(testing)
    - 프로그램의 정확한 수행 검증 <span style="color:yellow">(수행이 되는지 테스트)</span>
    - 프로그램의 성능 검사 
  - 오류 제거(error removal)
    - 독립적 단위로 테스트 후 전체 시스템으로 통합

>포인터와 동적 메모리 할당
- 포인터
  - C언어에서 어떤 타입에 대한 포인터 타입이 존재
  - 포인터 타입의 <u>실제값은 메모리 주소가 됨</u>
  - 포인터 연산자들
    - & : 주소 연산자
    - * : 역참조 연산자
  - 널포인터 : 어떠한 객체, 함수도 가리키지 않음
    - 정수 0값으로 표현
  - 포인터가 대상을 가리키지 않을 경우 값을 `NULL`로
  - 명시적인 타입 변환 ```(type cast): void *malloc(size_t size);```
- 동적 메모리 할당
  - 프로그램을 작성할 때 얼마나 많은 공간이 필요한지 알 수 없을 때 사용
  - 히프(heap) 사용
  - 새로운 메모리 공간이 필요할 때마다 `malloc` 호출해 필요한 양의 공간 요구
>알고리즘 명세
- 특정한 일을 수행하기 위한 명령의 유한 집합
- 조건
  - 입력 : (외부) 원인 >= 0 : 입력은 없을 수도 있을 수도 있음
  - 출력 : 결과 >= 1 :결과는 무조건 존재해야, 결과의 개수는 하나 이상
  - 명백성(definiteness) : 모호하지 않은 명확한 명령
  - 유한성(finiteness) : 종료, 반드시 종료되어야 함
  - 유효성(effectiveness) : 기본적, 실행 가능한 명령
    - Ex) program is similar algorithm (항상 종료된다는 관점에서)<br> 흐름도(flowchart) is simillar algorithm (알고리즘이 작고 단순한 경우) <u>여러 알고리즘의 집합 = 프로그램</u>
  >선택정렬(Selection Sort)
  - n>=1개의 서로 다른 정수를 정렬
    - 정렬되지 않은 정수들 중 가장 작은 값을 찾고,
    - 정렬된 리스트 다음 자리에 놓음
      - 정수들이 배열(array), list에 저장
      - i번째 정수는 list[i], 1<=i<=n에 저장
        ```
        for (i=0; i < n; i++>){
            list[i]에서부터 list[n-1]까지의 정수 값을 검사한 결과
            list[min]이 가장 작은 정수 값이라 하자;
            list[i]와 list[min]을 서로 교환;
        }
        ```
      - `list[min]`을 `list[i]`값과 교환하는 작업 `swap(&a, &b)`
        ```
        void swap(int *x, int *y)
        {
            int temp = *x // temp 변수를 int로 선언, x가 가리키는 주소의 내용 지정
            *x = *y // y가 가리키는 주소의 내용을 x가 가리키는 주소에 저장
            *y = temp // temp의 내용을 y가 가리키는 주소에 저장
        }
        ```
        매크로 정의도 가능
  >이진 탐색(Binary Search)
  - 정수 `searchnum`이 배열 `list`에 존재하는지 검사
    - <span style="color:yellow">조건 : 배열이 순서대로 정렬되어 있어야 한다.</span>
    - `searchnum`에 대하여 `list[i]=serchnum`인 인덱스 `i`를 반환
    - 초기값 : `left=0`, `right = n-1`
    - list의 중간 위치 : `middle=(left+right)/2`
    
       1. `list[middle]`이랑 찾는 `searchnum`을 비교
       2. `list[middle]`이 더 크다면 `right = middle -1`
       3. 같다면 `middle`반환
       4. 더 작다면 `left = middle + 1`
       5. 같을 때 까지 이 과정을 반복한다.
       6. 두 배열의 값의 비교 `compare()`은 `x`와`y`의 값 중 `x`가 크다면 `-1` 반환 같다면 `0` 반환 작다면 `1` 반환

  >순환 알고리즘(Recursive Algotithms)
  - 수행이 완료되기 전 <span style="color:yellow">자기 자신을 다시 호출</span>
    - 직접 순환(direct recursion) : (func_a -> func_a)
    - 간접 순환(indirect recursion) : (func_a -> func_b - > func_a)
  - 피보나치 수, 팩토리얼, 이항 계수
  - 이진 탐색에서 적용 가능
>데이터 추상화 (Data Abstraction)
  - 데이터타입(data type) = 객체(object) + 객체 위에 동작하는 연산(operation)들의 집합
  - 추상 자료형 (ADT: abstract data type)
    - 객체의 표현과 연산의 구현으로부터 분리된 독립된 자료형
    - ADT 연산의 명세
      - 기능에 대한 기술
      - 구현에 대한 자세한 설명은 필요없음
      - 따라서 구현에 독립적이다, 언어에 종속되지 않는다.
  - 데이터 타입 함수
    - 생성자/구성자 : 새 인스턴스를 생성
    - 변환자
    - 관찰자/보고자
>성능 분석 (Performance Measurement)
- 성능 평가
  - 성능분석 : 시간과 공간의 추산(예측)
  - 성능측정 : 실행 시간, 실측 성능
- 정의
  - 공간 복잡도 : 실행시켜 완료하는데 <span style="color:yellow">필요한 공간의 양(ex : Memory)</span>
  - 시간 복잡도 : 프로그램이 완료되는데 <span style="color:yellow">필요한 컴퓨터 시간의 양(ex : CPU time)</span>
- 공간 복잡도 (Space Complexity)
  - 고정 공간 요구
    - 명령어 공간, 단순 변수, 고정 크기의 구조화 변수, 상수 (Compile Time에 의해 정해지는 공간)
  - 가변 공간 요구
    - 문제의 인스턴스 I에 의존하는 공간
    - 가변 공간 (ex: 배열의 크기)
  - 공간 요구량 : S(P) = c + S<small>p</small>(I)
- 시간 복잡도 (Time Complexity)
  - 프로그램 P에 의해 소요되는 시간 : T(P) = 컴파일 시간 + T<small>p</small>(=실행시간)
  - 프로그램 단계
    - 의미적으로 독립성을 갖는 프로그램의 단위 -> 1 step 프로그램에서 한줄 계산
      - `a = 2 - 1 step`
      - `a = 2*b+3*a+4*g - 1 step`
    - 한 단계 실행 시간이 인스턴스 특성(Input의 Size)에 독립적
  - 단계의 계산 (방법 1)
    - 전역 변수 `count` 사용
    -  ```
        for(i=0; i<n; i++)
        {
            (함수 내용)
            count++
        }
        ```
        이 경우 `n step`
    
    - **얼마나 많은 단계가 수행되는지 말해줄 뿐, <br>얼마나 많은 시간을 소요하는지 말해주는 개념은 아님!** 
  - 단계의 계산 (방법 2)
    - 테이블 방식 : 단계 수 테이블
      - 문장의 대한 단계 수 : step//execution = s/e
      - 문장이 수행되는 횟수 : 빈도수(frequency)
      - 총 단계 수 : 빈도수 * s/e
- 요약
  - 프로그램의 시간복잡도
    - 프로그램이 취한 단계수로 표현
    - 중요한 특성만 선택
    - 입력수의 함수로만 계산 (ex.n)
  - 단계는 독립적인 연산단위
  - 이진탐색의 경우 리스트 원소의 수 n으로 단계수 결정은 부적절하다. 결과는 위치(입력)에 따라 다르기 때문이다.
  - Best Case, Worst Case, Average Case로 구분하여 단계 수를 정의할 필요가 있다. 
