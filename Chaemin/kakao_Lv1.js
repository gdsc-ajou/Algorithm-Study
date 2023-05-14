function solution(id_list, report, k) {
    const answer = new Array(id_list.length).fill(0);
    const report_list = {};
    
    id_list.map((user) => {
        report_list[user] = [];
    })
    
    report.map((user) => {
        const [userId, reportId] = user.split(' ');
        if(!report_list[reportId].includes(userId))
            report_list[reportId].push(userId);
    })
    
    for(let i in report_list) {
        if(report_list[i].length >= k) {
            report_list[i].map((user)=> {
                answer[id_list.indexOf(user)] += 1;
            })
        }
    }
    
    return answer;
}
