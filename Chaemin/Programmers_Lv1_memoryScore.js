function solution(name, yearning, photo) {
    var result = [];

    for (let i=0; i<photo.length; i++) {
        let sum=0;

        for(let j=0; j<name.length; j++) {
            if(photo[i].includes(name[j])) {
                sum += yearning[j];
            }
        }
    console.log(sum);
    result.push(sum);
    }

    return result;
}
