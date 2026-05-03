// // Write a function memoize that caches async functions

async function asyncCacheFn(ids, maxConcurrency) {
  const result = new Array(ids.length);
  let currIdx = 0;
  let activeIdx = 0;
  let completeCnt = 0;

  return new Promise((resolve) => {
    function start() {
      if (currIdx >= ids.length) {
        if (activeIdx === 0) {
          resolve(result);
        }
        return;
      }

      const index = currIdx;
      const id = ids[currIdx];
      currIdx++;
      activeIdx++;

      profileFetch(id)
        .then((res) => {
          result[index] = { id, res };
        })
        .catch(error => {
          result[index] = { error: true, id };
          //  console.error(err)
        })
        .finally(() => {
          activeIdx--;
          completeCnt++;
          start();
        });
    }

    for (let i = 0; i < Math.min(maxConcurrency, ids.length); ++i) {
      start();
    }
  });
}

function profileFetch(id) {
  return new Promise((resolve, reject) => {
    const delay = Math.random() * 3000 + 500;
    setTimeout(() => {
      if (Math.random() < 0.3) {
        reject(new Error(`Time out ${id}`));
      } else {
        resolve({ name: `USer ${id} `, age: 20 + id });
      }
    }, delay);
  });
}

const ids = [101, 202, 303, 404, 505];
asyncCacheFn(ids, 2).then((res) => {
  console.log(JSON.stringify(res, null, 2));
});
