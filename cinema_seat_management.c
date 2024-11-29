#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef long long ll;

#define MAX_SCREEN 100
#define MAX_ROW 100
#define MAX_COL 100

typedef struct {
    char name[50];
    ll rows;
    ll cols;
    ll screen[MAX_ROW][MAX_COL];
    ll aisles[MAX_COL];
    ll aisle_count;
} Screen;

Screen screens[MAX_SCREEN];
ll screen_count = 0;

bool is_aisle(ll num, ll aisle[], ll aisle_count) {
    for (ll i = 0; i < aisle_count; i++) {
        if (aisle[i] == num) {
            return true;
        }
    }
    return false;
}

void disp(ll *arr, ll len) {
    for (ll i = 0; i < len; i++) {
        if (i != len - 1) {
            printf("%lld ", arr[i]);
        } else {
            printf("%lld", arr[i]);
        }
    }
}

void add_screen(char str[][50], ll str_len) {
    ll aisles[MAX_COL];
    ll aisle_count = 0;
    bool flag = false;

    for (ll i = 0; i < screen_count; i++) {
        if (strcmp(screens[i].name, str[1]) == 0) {
            flag = true;
            break;
        }
    }

    if (flag) {
        printf("failure\n");
        return;
    }

    for (ll i = 4; i < str_len; i++) {
        aisles[aisle_count++] = atoll(str[i]) - 1;
    }

    Screen new_screen;
    strcpy(new_screen.name, str[1]);
    new_screen.rows = atoll(str[2]);
    new_screen.cols = atoll(str[3]);
    new_screen.aisle_count = aisle_count;

    for (ll i = 0; i < new_screen.rows; i++) {
        for (ll j = 0; j < new_screen.cols; j++) {
            if (is_aisle(j, aisles, aisle_count)) {
                new_screen.screen[i][j] = 2;  // aisle
            } else {
                new_screen.screen[i][j] = 0;  // empty seat
            }
        }
    }

    screens[screen_count++] = new_screen;
    printf("success\n");
}

void reserve_seat(char str[][50], ll str_len) {
    bool flag = false;
    ll index = 0;

    for (ll i = 0; i < screen_count; i++) {
        if (strcmp(screens[i].name, str[1]) == 0) {
            flag = true;
            index = i;
            break;
        }
    }

    if (!flag) {
        printf("failure\n");
        return;
    }

    ll row = atoll(str[2]) - 1;
    ll res_col[MAX_COL];
    ll res_col_count = 0;

    for (ll i = 3; i < str_len; i++) {
        res_col[res_col_count++] = atoll(str[i]) - 1;
    }

    flag = true;
    for (ll i = 0; i < res_col_count; i++) {
        if (screens[index].screen[row][res_col[i]] == 1 || screens[index].screen[row][res_col[i]] == 3) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        printf("failure\n");
        return;
    }

    for (ll i = 0; i < res_col_count; i++) {
        if (screens[index].screen[row][res_col[i]] == 0) {
            screens[index].screen[row][res_col[i]] = 1;  // reserved
        } else if (screens[index].screen[row][res_col[i]] == 2) {
            screens[index].screen[row][res_col[i]] = 3;  // aisle with reservation
        }
    }

    printf("success\n");
}

void get_unres(char str[][50], ll str_len) {
    bool flag = false;
    ll index = 0;

    for (ll i = 0; i < screen_count; i++) {
        if (strcmp(screens[i].name, str[1]) == 0) {
            flag = true;
            index = i;
            break;
        }
    }

    if (!flag) {
        printf("failure\n");
        return;
    }

    ll row = atoll(str[2]) - 1;
    ll pri[MAX_COL];
    ll pri_count = 0;

    for (ll i = 0; i < screens[index].cols; i++) {
        if (screens[index].screen[row][i] == 0 || screens[index].screen[row][i] == 2) {
            pri[pri_count++] = i + 1;
        }
    }

    disp(pri, pri_count);
    printf("\n");
}

bool occupied(ll *v, ll len) {
    bool flag = true;
    for (ll i = 0; i < len; i++) {
        if (v[i] == 1 || v[i] == 3) {
            flag = false;
            break;
        }
    }
    return flag;
}

void suggest_cont(char str[][50], ll str_len) {
    bool flag = false;
    ll index = 0;

    for (ll i = 0; i < screen_count; i++) {
        if (strcmp(screens[i].name, str[1]) == 0) {
            flag = true;
            index = i;
            break;
        }
    }

    if (!flag) {
        printf("failure\n");
        return;
    }

    ll row = atoll(str[3]) - 1;
    ll choice = atoll(str[4]) - 1;
    ll num = atoll(str[2]);
    ll pri[MAX_COL][MAX_COL];
    ll pri_count = 0;

    if (screens[index].screen[row][choice] == 1 || screens[index].screen[row][choice] == 3) {
        printf("none\n");
        return;
    }

    for (ll i = (choice - num + 1 < 0 ? 0 : choice - num + 1); i < (choice + num + 1 > screens[index].cols ? screens[index].cols : choice + num + 1); i++) {
        ll seats[MAX_COL];
        ll indices[MAX_COL];
        for (ll j = i; j < i + num; j++) {
            seats[j - i] = screens[index].screen[row][j];
            indices[j - i] = j + 1;
        }
        if (occupied(seats, num)) {
            for (ll k = 0; k < num; k++) {
                pri[pri_count][k] = indices[k];
            }
            pri_count++;
        }
    }

    if (pri_count == 0) {
        printf("none\n");
    } else {
        for (ll i = 0; i < pri_count; i++) {
            disp(pri[i], num);
            printf("\n");
        }
    }
}

int main() {
    ll t;
    scanf("%lld\n", &t);

    while (t--) {
        char str[10][50];
        char line[500];
        fgets(line, sizeof(line), stdin);

        ll str_len = 0;
        char *token = strtok(line, " \n");
        while (token != NULL) {
            strcpy(str[str_len], token);
            str_len++;
            token = strtok(NULL, " \n");
        }

        if (strcmp(str[0], "add-screen") == 0) {
            add_screen(str, str_len);
        } else if (strcmp(str[0], "reserve-seat") == 0) {
            reserve_seat(str, str_len);
        } else if (strcmp(str[0], "get-unreserved-seats") == 0) {
            get_unres(str, str_len);
        } else if (strcmp(str[0], "suggest-contiguous-seats") == 0) {
            suggest_cont(str, str_len);
        } else {
            printf("failure\n");
        }
    }

    return 0;
}
