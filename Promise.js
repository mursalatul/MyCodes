var timeLimit = function (fn, t) {
    return async function (...args) {
        return new Promise((resolve, rejected) => {
           const timeOutId =  setTimeout(() => {
                rejected("Time Limit Extend");
            }, t);

            fin(...args)
                .then((result) => {
                    clearTimeout(timeOutId);

                    resolve(result); 
                })
                .catch((error) => {
                    clearTimeout(timeOutId);
                    rejected(error);
                });
        });
    };
};

const limited = timeLimit((t) => new Promise((res) => setTimeout(res, t)), 100);
limited(150).catch(); // "Time Limit Exceeded" at t=100ms
