/* 
Sub: Async Await

*/

const myPromise = new Promise((resolved, rejected) => {
  const result = "null";

  if (!result) {
    rejected("promise rejected");
  } else {
    setTimeout(() => {
      resolved("Promises resolved");
    }, 1000);
  }
});

/* myPromise
    .then((res) => {
      console.log("🚀 ~ file: Promises.js:21 ~ .then ~ res:", res);
    })
    .catch((err) => {
      console.log("🚀 ~ file: Promises.js:23 ~ err:", err);
    });  */

async function myData() {
  const res = await myPromise;
  console.log(res);
}
myData();

/* fetch("")
  .then((res) => console.log(res))
  .catch((err) => console.log(err)); */

async function getData() {
  const res = await fetch("");
  const data = res.json();
  console.log("🚀 ~ file: AsyncAwait.js:40 ~ getData ~ data:", data);
}
