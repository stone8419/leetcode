/**
 * http://www.bubuko.com/
 * Note: The returned array must be malloced, assume caller calls free().
 */
int t;
int cmp(void* a,void* b)
{
    return *(int*)a-*(int*)b;
}
void dfs(int** land, int landSize, int* landColSize,int x,int y)
{
    int i,j;
    t++;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int nx=x+dx,ny=y+dy;
            if(nx>=0&&nx<landSize&&ny>=0&&ny<landColSize[0]&&land[nx][ny]==0){
                land[nx][ny]=1;
                dfs(land,landSize,landColSize,nx,ny);
            }
        }
    }
}
int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize){
    if(land==NULL||landSize==0){
        *returnSize=0;
        return NULL;
    }
    int* area=(int*)malloc(sizeof(int)*(landSize*landColSize[0]));
    int cnt=0,i,j;
    for(i=0;i<landSize;i++){
        for(j=0;j<landColSize[0];j++){
            if(land[i][j]==0){
                t=0;
                dfs(land,landSize,landColSize,i,j);
                area[cnt++]=t-1;
            }
        }
    }
    *returnSize=cnt;
    qsort(area,cnt,sizeof(int),cmp);
    return area;
}
